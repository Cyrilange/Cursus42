NAME        = minishell

LIBFT       = ./includes/libft

CC          = gcc
CFLAGS      = -g -Wall -Werror -Wextra -I$(LIBFT) -I./includes
LDFLAGS     = -lreadline


SRC_DIR     = ./src
OBJ_DIR     = ./obj

# List source files with path
SRC_FILES = \
	src/main.c \
	src/built_ins/cd_command.c \
	src/built_ins/pwd_command.c \
	src/built_ins/echo_command.c \
	src/user_input/opening_minishell.c \

# Convert source files into object files
OBJS        = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@

# Rule to build final executable
$(NAME): $(OBJS) $(LIBFT)/libft.a
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)/libft.a $(LDFLAGS)


# Rule to build libft
$(LIBFT)/libft.a:
	@$(MAKE) -C $(LIBFT)

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT) clean

# Clean all
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
