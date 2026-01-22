FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    php7.4 \
    php7.4-fpm \
    php7.4-mysql \
    wget \
    curl \
    mariadb-client \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /run/php

COPY conf/www.conf /etc/php/7.4/fpm/pool.d/
COPY tools/setup_wordpress.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/setup_wordpress.sh

EXPOSE 9000

ENTRYPOINT ["setup_wordpress.sh"]
