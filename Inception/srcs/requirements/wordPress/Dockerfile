FROM debian:bullseye


RUN apt-get update && apt-get install -y \
    apt-transport-https \
    lsb-release \
    ca-certificates \
    curl \
    gnupg \
    && curl -sSLo /usr/share/keyrings/deb.sury.org-php.gpg https://packages.sury.org/php/apt.gpg \
    && echo "deb [signed-by=/usr/share/keyrings/deb.sury.org-php.gpg] https://packages.sury.org/php/ $(lsb_release -sc) main" > /etc/apt/sources.list.d/php.list \
    && apt-get update


RUN apt-get install -y \
    php8.3 \
    php8.3-fpm \
    php8.3-mysql \
    php8.3-curl \
    php8.3-gd \
    php8.3-mbstring \
    php8.3-xml \
    php8.3-zip \
    php8.3-soap \
    php8.3-intl \
    mariadb-client \
    curl \
    wget \
    && rm -rf /var/lib/apt/lists/*


RUN mkdir -p /run/php


RUN sed -i 's|^listen = .*|listen = 9000|' /etc/php/8.3/fpm/pool.d/www.conf \
    && sed -i 's|^;listen.owner = .*|listen.owner = www-data|' /etc/php/8.3/fpm/pool.d/www.conf \
    && sed -i 's|^;listen.group = .*|listen.group = www-data|' /etc/php/8.3/fpm/pool.d/www.conf \
    && sed -i 's|^;listen.mode = .*|listen.mode = 0660|' /etc/php/8.3/fpm/pool.d/www.conf


COPY tools/setup_wordpress.sh /setup_wordpress.sh
RUN chmod +x /setup_wordpress.sh

 
EXPOSE 9000
ENTRYPOINT ["/setup_wordpress.sh"]