NAME = so_long

CC              = gcc -g
CFLAGS          = -Wall -Werror -Wextra 
MLX42_LIB       = ./MLX42/build/libmlx42.a
MLX42_INCLUDE   = ./MLX42/include
LIBFT           = ./includes/libft
FT_PRINTF       = ./includes/ft_printf
INCLUDES        = -I$(MLX42_INCLUDE) -Iincludes
LIBS            = -L./MLX42/build -lmlx42 -lglfw -ldl -lm -lpthread -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf -g

SRC_DIR         = ./src
OBJ_DIR         = ./obj

SRC_FILES       = 	get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c \
					check.c  flood.c  free_game.c  images.c  main.c  map.c  mouvement.c check_map.c \
					


OBJS            = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

# Cible par défaut qui construit tout
all: $(NAME)

# Construction de la libmlx42 si elle n'existe pas
$(MLX42_LIB):
	cmake -B MLX42/build -S ./MLX42
	cmake --build MLX42/build -j4

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(MLX42_LIB)
	@mkdir -p $(OBJ_DIR)/get_next_line
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation finale pour générer l'exécutable
$(NAME): $(OBJS) $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(MLX42_LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

# Règles pour construire libft
$(LIBFT)/libft.a:
	@$(MAKE) -C $(LIBFT)

$(FT_PRINTF)/libftprintf.a:
	@$(MAKE) -C $(FT_PRINTF)

# Cible de nettoyage pour supprimer les objets et les fichiers temporaires
clean:
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(FT_PRINTF) clean
	make clean -C ./MLX42/build
	@rm -rf $(OBJ_DIR)

# Nettoyage complet, y compris l'exécutable
fclean: clean
	@rm -f $(NAME) $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a
	make clean -C ./MLX42/build

# Cible pour tout reconstruire
re: fclean all

.PHONY: all clean fclean re
