#!/bin/bash
set -e

DATADIR="/var/lib/mysql"

mkdir -p /run/mysqld "$DATADIR" /var/log/mysql
chown -R mysql:mysql /run/mysqld "$DATADIR" /var/log/mysql

# Initialize database if mysql system folder doesn't exist
if [ ! -d "$DATADIR/mysql" ]; then
    echo "→ Initializing MariaDB database..."

    mysql_install_db --user=mysql --datadir="$DATADIR"

    # Temporary start without network
    mysqld --user=mysql --datadir="$DATADIR" --skip-networking &
    pid=$!

    # Wait for MariaDB to be ready
    echo "→ Waiting for MariaDB to be ready..."
    until mysqladmin ping -h localhost -u root --silent; do
        sleep 1
    done

    echo "→ Configuring users and database..."

    mysql -u root <<EOSQL
-- Create WordPress database
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`
CHARACTER SET utf8mb4
COLLATE utf8mb4_unicode_ci;

-- Secure root user
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
CREATE USER IF NOT EXISTS 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;

-- WordPress user with wildcards for Docker network
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'localhost' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'localhost';

FLUSH PRIVILEGES;
EOSQL

    echo "→ Database initialized successfully!"
    mysqladmin -u root -p"${MYSQL_ROOT_PASSWORD}" shutdown
    wait "$pid"
else
    echo "→ Database already initialized."
fi

# Final start
echo "→ Starting MariaDB..."
exec mysqld --user=mysql --datadir="$DATADIR" --bind-address=0.0.0.0