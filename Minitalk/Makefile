NAME_C = client
NAME_S = server
NAME_BONUS_C = client_bonus
NAME_BONUS_S = server_bonus

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PTINF_DIR = Printf
PTINF = $(PTINF_DIR)/libftprintf.a

GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

SRC_client = client.c
SRC_server = server.c
OBJ_client = $(SRC_client:.c=.o)
OBJ_server = $(SRC_server:.c=.o)

SRC_client_b = client_bonus.c
SRC_server_b = server_bonus.c
OBJ_client_b = $(SRC_client_b:.c=.o)
OBJ_server_b = $(SRC_server_b:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f


all: $(NAME_C) $(NAME_S)


bonus: $(NAME_BONUS_C) $(NAME_BONUS_S)

$(NAME_C): $(OBJ_client) $(LIBFT) $(PTINF)
	@echo "$(YELLOW)Compilation client...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_client) -L$(LIBFT_DIR) -L$(PTINF_DIR) -lft -lftprintf -o $(NAME_C)
	@echo "$(GREEN)Client OK !$(RESET)"

$(NAME_S): $(OBJ_server) $(LIBFT) $(PTINF)
	@echo "$(YELLOW)Compilation server...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_server) -L$(LIBFT_DIR) -L$(PTINF_DIR) -lft -lftprintf -o $(NAME_S)
	@echo "$(GREEN)Server OK !$(RESET)"

$(NAME_BONUS_C): $(OBJ_client_b) $(LIBFT) $(PTINF)
	@echo "$(YELLOW)Compilation bonus client...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_client_b) -L$(LIBFT_DIR) -L$(PTINF_DIR) -lft -lftprintf -o $(NAME_BONUS_C)
	@echo "$(GREEN)Client bonus OK !$(RESET)"

$(NAME_BONUS_S): $(OBJ_server_b) $(LIBFT) $(PTINF)
	@echo "$(YELLOW)Compilation bonus server...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_server_b) -L$(LIBFT_DIR) -L$(PTINF_DIR) -lft -lftprintf -o $(NAME_BONUS_S)
	@echo "$(GREEN)Server bonus OK !$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): 
	@echo "$(YELLOW)Compilation libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)LIBFT OK !$(RESET)"

$(PTINF): 
	@echo "$(YELLOW)Compilation printf...$(RESET)"
	@make -C $(PTINF_DIR)
	@echo "$(GREEN)PRINTF OK !$(RESET)"

clean:
	@$(RM) $(OBJ_client) $(OBJ_server) $(OBJ_client_b) $(OBJ_server_b)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PTINF_DIR) clean
	@echo "$(GREEN)clean OK !$(RESET)"

fclean: clean
	@$(RM) $(NAME_C) $(NAME_S) $(NAME_BONUS_C) $(NAME_BONUS_S)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PTINF_DIR) fclean
	@echo "$(GREEN)Fclean OK !$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re
