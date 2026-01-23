#!/bin/bash
set -e

DATADIR="/var/lib/mysql"

chown -R mysql:mysql $DATADIR
mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld

if [ ! -d "$DATADIR/mysql" ]; then
    mysql_install_db --user=mysql --datadir=$DATADIR

    mysqld --user=mysql --datadir=$DATADIR &
    pid="$!"

    until mysqladmin ping --silent; do
        sleep 1
    done

    mysql -u root << EOF
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOF

    mysqladmin shutdown
    wait "$pid"
fi

exec mysqld --user=mysql --datadir=$DATADIR
