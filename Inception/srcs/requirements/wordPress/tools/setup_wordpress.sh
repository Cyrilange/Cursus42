#!/bin/bash
set -e

WP_PATH=/var/www/html

if [ ! -f "$WP_PATH/wp-config.php" ]; then
    echo "Installing WordPress..."

    curl -s https://wordpress.org/latest.tar.gz | tar zx
    mv wordpress/* $WP_PATH
    rm -rf wordpress

    cp $WP_PATH/wp-config-sample.php $WP_PATH/wp-config.php

    sed -i "s/database_name_here/$MYSQL_DATABASE/" $WP_PATH/wp-config.php
    sed -i "s/username_here/$MYSQL_USER/" $WP_PATH/wp-config.php
    sed -i "s/password_here/$MYSQL_PASSWORD/" $WP_PATH/wp-config.php
    sed -i "s/localhost/mariadb/" $WP_PATH/wp-config.php
fi

echo "Starting php-fpm..."
exec php-fpm7.4 -F
