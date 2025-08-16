
ROSE = \033[38;5;205m
RESET = \033[0m
YELLOW = \033[1;33m
RED = \033[1;31m
BROWN = \033[1;33m
PURPLE = \033[1;35m
GOLD = \033[1;33m
BLUE = \033[1;34m
GREEN = \033[1;32m
MAGENTA = \033[1;35m

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g

SRCS = main.c \
initialisation/free_functions.c \
execution/print_status.c \
initialisation/error_functions.c \
initialisation/initialisation.c \
execution/executor.c \
initialisation/parseing.c \
initialisation/mutex_and_phtread_safety.c \
execution/philosophers_routine_describe.c \
initialisation/safety_value.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	@clear
	@echo "$(ROSE) <USAGE> $(RESET) $(BROWN)./philo $(RESET) $(GREEN)<numbers of philos>$(RESET) $(RED) <time to die> $(RESET) $(MAGENTA) <time to eat> $(RESET) $(BLUE) <time to sleep> $(RESET) $(GOLD) [number of meals]$(RESET)" \
	&& echo "" \
	&& echo "$(YELLOW)" \
	&& echo "██████╗ ██╗  ██╗██╗██╗      ██████╗ " \
	&& echo "██╔══██╗██║  ██║██║██║     ██╔═══██╗" \
	&& echo "██████╔╝███████║██║██║     ██║   ██║" \
	&& echo "██╔═══╝ ██╔══██║██║██║     ██║   ██║" \
	&& echo "██║     ██║  ██║██║███████╗╚██████╔╝" \
	&& echo "╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ " \
	&& echo "$(RESET)"


$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
		@echo "$(ROSE)GOOD BYE PHILO$(RESET)";



fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
