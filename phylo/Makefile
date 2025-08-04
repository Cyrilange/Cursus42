NAME = philo
CC = gcc 
CFLAGS = -Wall -Wextra -Werror -pthread -g
SRCS = main.c free_functions.c print_status.c error_functions.c initialisation.c executor.c parseing.c mutex_and_phtread_safety.c philosophers_routine_describe.c
OBJS = $(SRCS:.c=.o)
RM = rm -f
LIBS = -lpthread

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
