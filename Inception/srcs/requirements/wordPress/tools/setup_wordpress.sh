#!/bin/bash
# set -e

# Path where WordPress should be installed
WP_PATH="/var/www/html"

# Create directory if needed
mkdir -p "$WP_PATH"
chown -R www-data:www-data "$WP_PATH"
chmod -R 755 "$WP_PATH"

# Download WordPress only if directory is empty
if [ ! -f "$WP_PATH/wp-config.php" ] && [ ! -f "$WP_PATH/index.php" ]; then
    echo "→ Downloading WordPress..."
    wget -q https://wordpress.org/latest.tar.gz -O /tmp/wordpress.tar.gz
    tar -xzf /tmp/wordpress.tar.gz -C /tmp/
    cp -r /tmp/wordpress/. "$WP_PATH/"
    rm -rf /tmp/wordpress /tmp/wordpress.tar.gz
    chown -R www-data:www-data "$WP_PATH"
fi

# Wait for MariaDB to be ready
echo "→ Waiting for MariaDB on ${MYSQL_HOST} (user=${MYSQL_USER})..."
max_tries=60
counter=0
until mysqladmin ping -h "${MYSQL_HOST}" -u "${MYSQL_USER}" -p"${MYSQL_PASSWORD}" --silent; do
    if [ $counter -ge $max_tries ]; then
        echo "ERROR: MariaDB unreachable after ${max_tries} attempts (user=${MYSQL_USER})"
        echo "Check: mariadb logs, .env, Docker network"
        exit 1
    fi
    counter=$((counter+1))
    echo "MariaDB not ready yet... (${counter}/${max_tries})"
    sleep 3
done
echo "→ MariaDB is ready!"

# Install wp-cli if not already present
if [ ! -f "/usr/local/bin/wp" ]; then
    echo "→ Installing wp-cli..."
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp
fi

cd "$WP_PATH"

# Create wp-config.php only if it doesn't exist
if [ ! -f wp-config.php ]; then
    echo "→ Creating wp-config.php..."
    wp config create \
        --dbname="${MYSQL_DATABASE}" \
        --dbuser="${MYSQL_USER}" \
        --dbpass="${MYSQL_PASSWORD}" \
        --dbhost="${MYSQL_HOST}" \
        --dbcharset="utf8mb4" \
        --dbcollate="utf8mb4_unicode_ci" \
        --allow-root \
        --skip-check
fi

# Install WordPress only if not already installed
if ! wp core is-installed --allow-root; then
    echo "→ Installing WordPress..."
    
    # Create admin first
    wp core install \
        --url="${WP_URL}" \
        --title="${WP_TITLE}" \
        --admin_user="${WP_ADMIN_USER}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --skip-email \
        --allow-root

    # Then create regular user (different from admin)
    echo "→ Creating user ${WP_USER}..."
    wp user create \
        "${WP_USER}" \
        "${WP_USER_EMAIL}" \
        --user_pass="${WP_USER_PASSWORD}" \
        --role=author \
        --allow-root
fi

# Force siteurl and home to https (important for nginx ssl)
wp option update siteurl "https://${DOMAIN_NAME}" --allow-root || true
wp option update home    "https://${DOMAIN_NAME}" --allow-root || true

# Debug if enabled
if [ "${WP_DEBUG}" = "true" ]; then
    wp config set WP_DEBUG true --raw --allow-root
    wp config set WP_DEBUG_LOG true --raw --allow-root
    wp config set WP_DEBUG_DISPLAY false --raw --allow-root
fi

# Final permissions
chown -R www-data:www-data "$WP_PATH"
find "$WP_PATH" -type d -exec chmod 755 {} \;
find "$WP_PATH" -type f -exec chmod 644 {} \;

echo "→ WordPress is ready! Starting php-fpm..."

# Start php-fpm in foreground (key to keep container alive)
exec php-fpm8.3 -F