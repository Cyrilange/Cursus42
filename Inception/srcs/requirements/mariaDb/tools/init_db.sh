#!/bin/bash
set -e

DATADIR="/var/lib/mysql"

mkdir -p /run/mysqld "$DATADIR" /var/log/mysql
chown -R mysql:mysql /run/mysqld "$DATADIR" /var/log/mysql

# Toujours initialiser si le dossier system n'existe pas
if [ ! -d "$DATADIR/mysql" ]; then
    echo "→ Initialisation de la base MariaDB..."

    mysql_install_db --user=mysql --datadir="$DATADIR"

    # Démarrage temporaire sans réseau
    mysqld --user=mysql --datadir="$DATADIR" --skip-networking &
    pid=$!

    # Attente plus robuste avec root password
    echo "→ Attente que MariaDB soit prêt..."
    until mysqladmin ping -h localhost -u root --silent; do
        sleep 1
    done

    echo "→ Configuration des utilisateurs et base..."

    mysql -u root <<EOSQL
-- Create WordPress database
CREATE DATABASE IF NOT EXISTS `wordpress`
CHARACTER SET utf8mb4
COLLATE utf8mb4_unicode_ci;

-- Secure root user
DROP USER IF EXISTS 'root'@'%';
CREATE USER 'root'@'%' IDENTIFIED BY 'rootpass';
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;

-- WordPress user (hardcodé pour debug)
DROP USER IF EXISTS 'csalamit'@'%';
CREATE USER 'csalamit'@'%' IDENTIFIED BY 'user';
GRANT ALL PRIVILEGES ON `wordpress`.* TO 'csalamit'@'%';

-- Optional admin user
DROP USER IF EXISTS 'admin'@'%';
CREATE USER 'admin'@'%' IDENTIFIED BY 'user';
GRANT ALL PRIVILEGES ON `wordpress`.* TO 'admin'@'%';

FLUSH PRIVILEGES;
EOSQL

    mysqladmin shutdown
    wait "$pid"
else
    echo "→ Base déjà initialisée, skip init users."
fi

# Démarrage final
exec mysqld --user=mysql --datadir="$DATADIR" --bind-address=0.0.0.0