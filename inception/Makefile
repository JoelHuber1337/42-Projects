NAME = inception
COMPOSER = srcs/docker-compose.yml
COMPOSITION = docker compose -f $(COMPOSER)

RED = \033[31m
RESET = \033[0m

all: build up

env:
	@if [ ! -f srcs/.env ]; then \
		printf "$(RED)MISSING ENV VARIABLES !!!!$(RESET)\n"; \
		exit 1; \
	fi

build: env
	$(COMPOSITION) build

up: env
	$(COMPOSITION) up -d

down: env
	$(COMPOSITION) down

stop: env
	$(COMPOSITION) stop

start: env
	$(COMPOSITION) start

restart: stop start

logs: env
	$(COMPOSITION) logs -f

ps: env
	$(COMPOSITION) ps

clean: env down
	$(COMPOSITION) down -v --remove-orphans || true

fclean: env clean
	docker system prune -af --volumes 2>/dev/null || true

re: env fclean all

.PHONY: all env build up down stop start restart logs ps clean fclean re