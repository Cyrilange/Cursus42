FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/*

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY conf/default.conf /etc/nginx/sites-available/default
COPY tools/execute.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/execute.sh

EXPOSE 443

ENTRYPOINT ["execute.sh"]
