
NAME            = cub3D
CC              = cc
CFLAGS          = -Wall -Wextra -Werror -g
MLX42_LIB       = ./Include/MLX42/build/libmlx42.a
MLX42_INCLUDE   = ./Include/MLX42/include
LIBFT           = ./Include/libft
GNL             = ./Include/get_next_line
INCLUDES        = -I$(MLX42_INCLUDE) -IInclude -I$(LIBFT) -I$(FT_PRINTF) -I$(GNL)
LIBS            = -L./Include/MLX42/build -lmlx42 -lglfw -ldl -lm -lpthread -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf -g

SRC_DIR         = ./Src
OBJ_DIR         = ./obj

SRC_FILES       = main.c \
				  initialisation/player.c \
				  initialisation/screen.c \
				  initialisation/game.c \
				  initialisation/textures.c \
				  tool/tool_part1.c \
				  tool/tool_part_2.c \
				  parsing/color.c \
				  parsing/line.c \
				  raycasting/draw_col.c \
				  raycasting/raycast.c \
				  controls/mouvement.c \
				  controls/monitor.c \
				  controls/move.c \
				  check/name.c \

OBJS            = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

PINK            = \033[1;35m
RESET           = \033[0m

all: $(NAME)


$(MLX42_LIB):
	cmake -B Include/MLX42/build -S ./Include/MLX42
	cmake --build Include/MLX42/build -j4


OBJ_DIRS := $(sort $(dir $(OBJS)))


$(OBJ_DIRS):
	mkdir -p $@


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIRS) $(MLX42_LIB)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)/libft.a $(GNL)/libgnl.a $(MLX42_LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(GNL)/libgnl.a $(LIBS)
	@clear
	@echo "$(PINK)" 
	@echo " ██████   ██    ██   ████████    ██████    ██████  "
	@echo " ██       ██    ██   ██  ████        ██    ██   ██ "
	@echo " ██       ██    ██   ██  ██       █████    ██   ██ "
	@echo " ██       ██    ██   ██  ████        ██    ██   ██ "
	@echo " ██████    ██████    ████████    ██████    ██████  "
	@echo "$(RESET)"
	@echo "\033[1;34m usage: ./cub3D [maps][maps_not_valid]/yourchoice \033[0m"
	@echo ""

# Build Libft
$(LIBFT)/libft.a:
	@$(MAKE) -C $(LIBFT)

# Build GNL
$(GNL)/libgnl.a:
	@$(MAKE) -C $(GNL)

clean:
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(GNL) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(PINK)$(NAME) BYE$(RESET)"

fclean: clean
	@rm -f $(NAME) $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(GNL)/libgnl.a
	@echo "$(PINK)$(NAME) BYE$(RESET)"

re: fclean all

.PHONY: all clean fclean re
