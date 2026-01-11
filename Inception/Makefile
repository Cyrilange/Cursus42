COMPOSE_FILE = srcs/docker-compose.yml

all: up

up: $(COMPOSE_FILE)
	@ sudo docker-compose -f $(COMPOSE_FILE) up --build -d
	@ touch up
	@ echo >up Inception succesfully up !

down:
	@ sudo docker-compose -f $(COMPOSE_FILE) down
	@ rm -f up

clean:
	@ sudo docker-compose -f $(COMPOSE_FILE) down -v --remove-orphans
	@ sudo docker system prune -f --volumes
	@ rm -f up

fclean:
	docker stop $$(docker ps -qa); docker rm $$(docker ps -qa); docker rmi -f $$(docker images -qa); docker volume rm $$(docker volume ls -q); docker network rm $$(docker network ls -q) 2>/dev/null 

re: clean all

.PHONY: all down clean re