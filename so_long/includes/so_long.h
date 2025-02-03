
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

#define FORMULA x * WIDTH / game->width, y * HEIGHT / game->height

#define WIDTH 512
#define HEIGHT 512

typedef struct s_pos
{
    int x;
    int y;
} t_pos;

typedef struct s_map
{
    int x;
    int y;
    mlx_t       *mlx;
    char        **map;
    int         width;
    int         height;
    mlx_image_t *wall;
    mlx_image_t *floor;
    mlx_image_t *collectible;
    mlx_image_t *player;
    mlx_image_t *exit;
    void        *window;
    struct s_map *next;
    int         collectibles;
    t_pos       player_pos; // Position du joueur
} t_map;

void	flood_fill(char **tab, t_map size, t_map begin);
void    init_game(t_map *game, const char *map_name);
char	**load_map(char *file, int *width, int *height);
void   	init_images(t_map *game);
void	render_game(t_map *game);
void	free_all(t_map  *game, int error);
//int		check_exit(t_map *col, char target);
void	find_player_position(t_map *game);
void	move_player(t_map *game, int new_x, int new_y);
void	free_map(char **map);
char *get_map_path(const char *map_name);







#endif