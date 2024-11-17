NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	  check.c \
	  is_sorted.c \
	  position.c \
	  push_swap_utils.c\
	  push.c\
	  rotate_left.c\
	  rotate_right.c\
	  sort_small.c\
	  swap.c\
	  error_free.c\


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

