FROM debian:bullseye

RUN apt-get update && \
    apt-get install -y nginx openssl && \
    rm -rf /var/lib/apt/lists/*

RUN mkdir -p /etc/nginx/ssl /var/www/html

RUN openssl req -x509 -nodes \
    -out /etc/nginx/ssl/inception.crt \
    -keyout /etc/nginx/ssl/inception.key \
    -subj "/C=ES/ST=Andalucia/L=Malaga/O=42/OU=42/CN=csalamit.42.fr/UID=csalamit"

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY tools/execute.sh /execute.sh


RUN chmod +x /execute.sh

EXPOSE 443

CMD ["/execute.sh"]
