COMPOSE_FILE = srcs/docker-compose.yml
PROJECT_NAME = srcs

all: up

up: $(COMPOSE_FILE)
	@echo "[i] Starting Inception..."
	@sudo docker compose -f $(COMPOSE_FILE) up --build -d
	@touch up
	@echo "[i] Inception successfully up !"

down:
	@echo "[i] Stopping Inception..."
	@sudo docker compose -f $(COMPOSE_FILE) down
	@rm -f up

clean:
	@echo "[i] Cleaning Inception..."
	@sudo docker compose -f $(COMPOSE_FILE) down -v --remove-orphans
	@sudo docker system prune -f --volumes
	@rm -f up

fclean:
	@echo "[i] Force cleaning everything..."
	@sudo docker compose -f $(COMPOSE_FILE) down -v --remove-orphans 2>/dev/null || true
	@sudo docker stop $$(sudo docker ps -qa) 2>/dev/null || true
	@sudo docker rm $$(sudo docker ps -qa) 2>/dev/null || true
	@sudo docker rmi -f $$(sudo docker images -qa) 2>/dev/null || true
	@sudo docker volume rm $$(sudo docker volume ls -q) 2>/dev/null || true
	@sudo docker network rm $$(sudo docker network ls -q) 2>/dev/null || true
	@sudo docker system prune -af --volumes 2>/dev/null || true
	@rm -f up

re: fclean all

.PHONY: all up down clean fclean re