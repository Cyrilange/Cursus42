# Developer documentation 

-------------

# 1-Set up the environment from scratch (prerequisites, configuration files, secrets).

### General system requirements

To install Docker Desktop successfully, your Linux host must meet the following general requirements:

64-bit kernel and CPU support for virtualization.
KVM virtualization support. Follow the KVM virtualization support instructions to check if the KVM kernel modules are enabled and how to provide access to the KVM device.
QEMU must be version 5.2 or later. We recommend upgrading to the latest version.
systemd init system.
GNOME, KDE, or MATE desktop environments are supported but others may work.
For many Linux distributions, the GNOME environment does not support tray icons. To add support for tray icons, you need to install a GNOME extension. For example, AppIndicator.
At least 4 GB of RAM.
Enable configuring ID mapping in user namespaces, see File sharing. Note that for Docker Desktop version 4.35 and later, this is not required anymore.
Recommended: Initialize pass for credentials management.

### Set up 
for the subject we need to use a VM :
open the VM , create a new Vm with your settings and the image of your choice ( I took debian)
make your basic instalation
to make things easier I create a remote vs-code using ssh ex :
ssh:localhost:2222

install docker 
install docker compose : 
create a makefile + a docker-compose.yml
create a source file, inside create the directories you need with each of them a Dockerfile

create a file .env so you can store your password and not push them, they need to stay private

--------------------------------

# 2-Build and launch the project using the Makefile and Docker Compose.

because of the makefile then the docker-compose.yml and then the differents dockerfile
To build it you shall open the terminal and write make 

# 3-Use relevant commands to manage the containers and volumes.

check if it is on and the name of the differents informations with : 
docker ps

you will have the name of container Id, image, command , when it is created , the ports and finally the names

Build : 
docker compose build {name}
docker compose up -d {name}

It allows you to build only one directory

test if up : 
docker logs -f {name} (via an other terminal )

Delete container : 
docker compose down -v

if you do ( docker compose down -v && docker compose build --no-cache mariadb && docker compose up mariadb ) you will delete a container and start again .

to see what happen in our container : 
docker logs mariadb

test wordpress to ake sure the website is on and comunicate with mariaDb :
curl -k https://localhost

exemple to check if users has been created :
docker exec mariadb mysql -u root -prootpass -e "SELECT user, host FROM mysql.user WHERE user='csalamit';"

connect in mariaDb container :
1-docker exec -it mariadb bash
2-mysql -u $MYSQL_USER -p

###### MariaDB / mysql [(none)]>

# once you are inside the database  :
SHOW DATABASES;
USE wordpress;
SHOW TABLES;
SELECT user, host FROM mysql.user;

CREATE USER 'test'@'%' IDENTIFIED BY 'testpass';


MySQL / MariaDB quick usage tutorial:

connect to the database:
docker exec -it mariadb mysql -u root -p

list databases:
SHOW DATABASES;

use a database:
USE wordpress;

show tables:
SHOW TABLES;

create a database:
CREATE DATABASE my_database;

create a user:
CREATE USER 'my_user'@'%' IDENTIFIED BY 'mypassword';

give privileges:
GRANT ALL PRIVILEGES ON my_database.* TO 'my_user'@'%';
FLUSH PRIVILEGES;

check users:
SELECT user, host FROM mysql.user;

exit mysql:
EXIT;


# 4-Identify where the project data is stored and how it persists.

---------------------------------------------------------------------------------------

the volumes are stored in Home then data as per dockerfile :

volumes:
  mariadb_data:
    driver: local
    driver_opts:
      type: none
      device: ~/data/mariadb
      o: bind
  wordpress_data:
    driver: local
    driver_opts:
      type: none
      device: ~/data/wordpress
      o: bind


	  DRIVER    VOLUME NAME
local     srcs_mariadb_data
local     srcs_wordpress_data
