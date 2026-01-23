COMPOSE_FILE = docker-compose.yml

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
	@docker stop $$(docker ps -qa) 2>/dev/null || true
	@docker rm $$(docker ps -qa) 2>/dev/null || true
	@docker rmi -f $$(docker images -qa) 2>/dev/null || true
	@docker volume rm $$(docker volume ls -q) 2>/dev/null || true
	@docker network rm $$(docker network ls -q) 2>/dev/null || true

re: fclean all

.PHONY: all up down clean fclean re
