FROM debian:bullseye

RUN apt-get update && \
    apt-get install -y mariadb-server && \
    rm -rf /var/lib/apt/lists/*

COPY conf/50-server.conf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/init_db.sh /init_db.sh

RUN chmod +x /init_db.sh

ENTRYPOINT ["/init_db.sh"]
