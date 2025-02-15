
#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <memory.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "../src/get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

//# define HEIGHT 640
//# define WIDHT 820
#define TILE_SIZE 40
#define WIDTH  1920
#define HEIGHT 1080


# define PLAYER 'P'
# define WALL '1'
# define FLOOR '0'
# define COLLECTIBLE 'C'   
# define EXIT 'E'

# define ERR -1
# define FAIL 1
# define SUCCESS 0

# define TRUE 1
# define FALSE 0
# define bool

typedef enum s_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}	t_dir;

typedef enum e_action
{
	NO_ACTION,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	EXIT_GAME
}	t_action;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_graphics
{
    mlx_texture_t *floor;
    mlx_texture_t *wall;
    mlx_texture_t *player;
    mlx_texture_t *exit;
    mlx_texture_t *collectible;
    mlx_image_t *floor_img;
    mlx_image_t *wall_img;
    mlx_image_t *player_img;
    mlx_image_t *exit_img;
    mlx_image_t *collectible_img;
} t_graphics;

typedef struct s_grid
{
	int	*floor;
	int	*wall;
	int	*player;
	int	*exit;
	int	*collectible;
}	t_grid;

typedef struct s_map_node
{
	char				*map;
	struct	s_map_node	*next;

}	t_map_node;

typedef	struct	s_key_mouv
{
	int	key;
}	t_key_mouv;

typedef struct s_game
{
	mlx_t		*mlx;
	t_graphics	images;
	t_graphics	textures;
	t_grid		grid;
	t_map_node	*map;
	t_coord		player;
	t_coord		size_pix;
	char		**grid_b;
	char		**grid_y;
	char		*path;
	int			mouv;
	int			collect_taken;
	t_dir		direction_player;
}	t_game;

t_game  int_game_function(t_game *game);
t_game	*init_flood_fill(t_game *game);
int		error_init_game(t_game *game, t_grid objects);
void	ft_game_loop(void *param);
void	init_textures(t_game *game);
void	init_images(t_game *game);
void	ft_handle_input(t_game *game);
void	init_textures(t_game *game);
void	init_images(t_game *game);
t_grid	*read_map(t_game *game);




#endif