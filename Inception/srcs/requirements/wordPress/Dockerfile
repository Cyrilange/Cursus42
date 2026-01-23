FROM debian:bullseye
RUN apt-get update && apt-get install -y php7.4 php7.4-fpm php7.4-mysql wget curl mariadb-client && rm -rf /var/lib/apt/lists/*
CMD ["php-fpm7.4", "-F"]
