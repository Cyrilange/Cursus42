# User documentation

# 1-Understand what services are provided by the stack.

This project uses Docker and Docker Compose to deploy a complete web stack.  
The stack is composed of the following services:

- **NGINX**  
  Acts as a reverse proxy and web server.  
  It listens on port 443 (HTTPS) and forwards requests to WordPress using SSL/TLS certificates.

- **WordPress (PHP-FPM)**  
  Hosts the WordPress application.  
  It communicates with the MariaDB database to store and retrieve website content.

- **MariaDB**  
  Relational database management system used by WordPress.  
  It stores users, posts, pages, and all WordPress-related data.

Each service runs in its own container and communicates through a Docker network.

--------------------------------------------

# 2-Start and stop the project.

To start the project, open a terminal at the root of the project and run:

make

This command builds the Docker images and starts all services using Docker Compose,
according to the rules defined in the Makefile.

To stop the project and remove the running containers:

make down

To remove containers, images, and volumes created by the project:

make clean

To fully reset the project (containers, images, volumes, and data):

make fclean


--------------------------------------------

# 3-Access the website and the administration panel.

Once the containers are running, you can access:

- **The website**  
  
  https://csalamit.42.fr

- **WordPress administration panel**  
 https://csalamit.42.fr/wp-admin  
  or  
  https://your_domain_name/wp-admin

Use the WordPress credentials defined during the setup to log in.

--------------------------------------------

# 4-Locate and manage credentials.

All sensitive credentials are stored in a `.env` file at the root of the file requirement.  
This file is not pushed to the repository.

The `.env` file contains:

MYSQL_ROOT_PASSWORD=?
MYSQL_DATABASE=?
MYSQL_USER=?
MYSQL_PASSWORD=?
MYSQL_ADMIN=?
MYSQL_ADMIN_PASSWORD=?
MYSQL_HOST=?
WP_TITLE=?
WP_URL=?
WP_ADMIN_USER=?
WP_ADMIN_PASSWORD=?
WP_ADMIN_EMAIL=?
WP_USER=?
WP_USER_PASSWORD=?
WP_USER_EMAIL=?
DOMAIN_NAME=?
WP_DEBUG=?
WP_PATH=?
These variables are injected into the containers using Docker Compose.

----------------------------------------------

# 5-Check that the services are running correctly.

To verify that containers are running:

docker ps
docker network ls

To check logs of a specific service:

docker logs nginx  
docker logs wordpress  
docker logs mariadb

To check database access:

docker exec -it mariadb mysql -u root -p

To test the website from the terminal:

curl -k https://localhost or go to internet with https://login.42.fr

If all services are running and accessible, the stack is correctly deployed.
the add a post or a comment , well play with wordpress and mariadb ...