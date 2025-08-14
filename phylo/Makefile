ROSE = \033[38;5;205m
RESET = \033[0m

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g
SRCS = main.c free_functions.c print_status.c error_functions.c initialisation.c executor.c parseing.c mutex_and_phtread_safety.c philosophers_routine_describe.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	@echo "$(ROSE)philo is ready !!! to use: ./philo <numbers of philos> <time to die> <time to eat> <time to sleep> [number of meals]$(RESET)" \
	

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