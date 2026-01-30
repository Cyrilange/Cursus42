#!/bin/bash
# set -e

# Chemin où WordPress doit être installé
WP_PATH="/var/www/html"

# Créer le dossier si besoin
mkdir -p "$WP_PATH"
chown -R www-data:www-data "$WP_PATH"
chmod -R 755 "$WP_PATH"

# Télécharger WordPress seulement si le dossier est vide
if [ ! -f "$WP_PATH/wp-config.php" ] && [ ! -f "$WP_PATH/index.php" ]; then
    echo "→ Téléchargement de WordPress..."
    wget -q https://wordpress.org/latest.tar.gz -O /tmp/wordpress.tar.gz
    tar -xzf /tmp/wordpress.tar.gz -C /tmp/
    cp -r /tmp/wordpress/. "$WP_PATH/"
    rm -rf /tmp/wordpress /tmp/wordpress.tar.gz
    chown -R www-data:www-data "$WP_PATH"
fi

# Attendre que MariaDB soit prêt – on teste avec l'utilisateur WordPress (plus fiable)
echo "→ Attente de MariaDB sur ${MYSQL_HOST} (user=${MYSQL_USER})..."
max_tries=60
counter=0
until mysqladmin ping -h "${MYSQL_HOST}" -u "${MYSQL_USER}" -p"${MYSQL_PASSWORD}" --silent; do
    if [ $counter -ge $max_tries ]; then
        echo "ERREUR : MariaDB inaccessible après ${max_tries} tentatives (user=${MYSQL_USER})"
        echo "Vérifiez : logs mariadb, .env, réseau Docker"
        exit 1
    fi
    counter=$((counter+1))
    echo "MariaDB pas encore prêt... (${counter}/${max_tries})"
    sleep 3   # 3 secondes pour être plus tolérant
done
echo "→ MariaDB est prêt !"

# Installer wp-cli si pas déjà présent
if [ ! -f "/usr/local/bin/wp" ]; then
    echo "→ Installation de wp-cli..."
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp
fi

cd "$WP_PATH"

# Créer wp-config.php seulement s'il n'existe pas
if [ ! -f wp-config.php ]; then
    echo "→ Création de wp-config.php..."
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

# Installer WordPress seulement si pas déjà installé
if ! wp core is-installed --allow-root; then
    echo "→ Installation de WordPress..."
    wp core install \
        --url="${WP_URL}" \
        --title="${WP_TITLE}" \
        --admin_user="${WP_USER}" \
        --admin_password="${WP_USER_PASSWORD}" \
        --admin_email="${WP_USER_EMAIL}" \
        --skip-email \
        --allow-root

    # Créer un utilisateur normal (optionnel mais demandé dans Inception)
    wp user create \
        "${WP_USER}" \
        "${WP_USER_EMAIL}" \
        --user_pass="${WP_USER_PASSWORD}" \
        --role=author \
        --allow-root || true
fi

# Forcer siteurl et home en https (important pour nginx ssl)
wp option update siteurl "https://${DOMAIN_NAME}" --allow-root || true
wp option update home    "https://${DOMAIN_NAME}" --allow-root || true

# Debug si activé
if [ "${WP_DEBUG}" = "true" ]; then
    wp config set WP_DEBUG true --raw --allow-root
    wp config set WP_DEBUG_LOG true --raw --allow-root
    wp config set WP_DEBUG_DISPLAY false --raw --allow-root
fi

# Permissions finales
chown -R www-data:www-data "$WP_PATH"
find "$WP_PATH" -type d -exec chmod 755 {} \;
find "$WP_PATH" -type f -exec chmod 644 {} \;

echo "→ WordPress est prêt ! Lancement de php-fpm..."

# Lancer php-fpm en foreground (clé pour que le container reste vivant)
exec php-fpm8.3 -F