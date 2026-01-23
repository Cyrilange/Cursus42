
Build : docker compose build {$req}
        docker compose up -d {$req}




check docker : docker ps


test if up : docker logs -f {$req}



Delete container : docker compose down -v

if you do (  docker compose down -v && \ docker compose build --no-cache mariadb && \ docker compose up mariadb
) you will delete a container and start again .


Open a new terminal to connect to the data base : docker exec -it mariadb mysql -u root -p or docker exec -it mariadb mysql -u wp_user -p

to see what happen in our container : docker logs {$IMAGE}

when you are in other terminal you shall write sudo before docker ps
