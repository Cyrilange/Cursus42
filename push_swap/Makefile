NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

GREEN = \033[0;92m
RED = \033[0;91m

SRC = main.c \
	  check.c \
	  push_swap_utils.c\
	  push.c\
	  rotate_left.c\
	  rotate_right.c\
	  sort_small.c\
	  swap.c\
	  push_swap_util_aux.c\
	  push_swap.c\
	  move_to_b.c\
	  ft_split.c \
	  move_back_to_a.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "${GREEN}Compiling is done for ${NAME}, you can now use it  ${RED}./push_swap"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

