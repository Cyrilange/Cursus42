
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
    char    **grid;
    int     width;
    int     height;
    t_coord player_coord;
} t_map;

typedef struct s_game
{
    mlx_t   *mlx;
    t_map   *map;
    mlx_image_t *floor;
    mlx_image_t *wall;
    mlx_image_t *player;
    mlx_image_t *exit;
    mlx_image_t *collectible;
} t_game;


void free_map(t_map *map);
t_map *read_map(const char *file);
int count_line(const char *file);
int validate_map(t_map *map);
void key_press(mlx_key_data_t keydata, void *param);
t_game *init_game(t_game *game, char *map_file);
void display_map(t_game *game);
void load_textures(t_game *game);
mlx_image_t *load_and_convert_texture(t_game *game, const char *file_path);
void free_game(t_game *game);
int ft_strlen_so(char *str);
void init_player_position(t_game *game);






#endif