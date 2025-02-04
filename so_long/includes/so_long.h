
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

# define HEIGHT 320
# define WIDHT 320

typedef enum s_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NUM_DRC
}	t_dir;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_map 
{
	char			**grid;
	int				width;
	int				height;
	mlx_t   		*mlx;
    mlx_image_t		*image;
	mlx_image_t		*floor;
    mlx_image_t		*wall;
    mlx_image_t		*player;
    mlx_image_t		*exit;
	mlx_image_t		*collectible;
	t_coord			player_coord;
} t_map;


void free_map(t_map *map);
t_map *read_map(const char *file);
int count_line(const char *file);
int validate_map(t_map *map);
void key_press(mlx_key_data_t keydata, void *param);
t_map *init_game(t_map *game, char *map_file);
void display_map(t_map *game);
void load_textures(t_map *game);
void free_game(t_map *game);
int ft_strlen_so(char *str);






#endif