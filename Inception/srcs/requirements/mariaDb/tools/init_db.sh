#!/bin/sh

set -e

if [ ! -d "/var/lib/mysql/${MYSQL_DATABASE}" ]; then

	cat << EOF > /tmp/create_db.sql
USE mysql;
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';

CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
ALTER DATABASE ${MYSQL_DATABASE} CHARACTER SET utf8 COLLATE utf8_general_ci;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

	mysqld --user=mysql --bootstrap < /tmp/create_db.sql
	chown -R www-data /var/lib/mysql
	chmod -R 777 /var/lib/mysql
	if [ $? -ne 0 ]; then
		echo "Error: Failed to create database and user.";
		exit 1
	fi
	echo "Database and user created successfully"
fi

chown -R www-data /var/lib/mysql
chmod -R 777 /var/lib/mysql

exec mysqld_safe --user=mysql --bind-address=0.0.0.0