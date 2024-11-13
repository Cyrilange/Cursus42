NAME = libftprintf.a

SRC = ft_hex_lowercase.c \
      ft_hex_upper.c \
      ft_print_pointer.c \
      ft_printf.c \
      ft_putchar.c \
      ft_putnbr.c \
      ft_putstr.c \
      ft_strlen.c \
      ft_unsigned_nbr.c

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -csr
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

