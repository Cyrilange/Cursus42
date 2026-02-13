
NAME = ft_transcendence

.PHONY: all up clean fclean re logs

# By default, build and start everything
all: up

# Build and run all Docker services
up:
	docker-compose up --build -d

# Show logs of all services
logs:
	docker-compose logs -f

# Stop containers and remove anonymous volumes
clean:
	docker-compose down

# Remove containers, volumes, networks, and images built by compose
fclean: clean
	docker-compose down --rmi all -v

# Rebuild everything from scratch
re: fclean up
