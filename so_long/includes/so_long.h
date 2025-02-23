
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
# include "../src/get_next_line/get_next_line.h"

# define WIDTH 36
# define HEIGHT 38

# define SUCCESS 0
# define ERROR 1

typedef struct s_texture
{
	void		*t;
	mlx_image_t	*i;
}				t_texture;

typedef struct s_images
{
	t_texture	wall;
	t_texture	floor;
	t_texture	player;
	t_texture	exit;
	t_texture	collectable;
}				t_images;

typedef struct s_window
{
	int			max_width;
	int			max_height;
}				t_window;

typedef struct s_map
{
	int			fd;
	int			map_width;
	int			map_height;
	char		**map;
}				t_map;

typedef struct s_play_pos
{
	int			player_x_pos;
	int			player_y_pos;
	int			exit_x_pos;
	int			exit_y_pos;

}				t_play_pos;

typedef struct s_count
{
	int			n_loves;
	int			n_player;
	int			n_exit;
	int			moves;
}				t_count;

typedef struct s_dir
{
	int			x;
	int			y;
}				t_dir;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		file;
	t_play_pos	position;
	t_count		count;
	void		*window;
	t_window	window_size;
	t_images	img;
	t_dir		dir;
}				t_game;

int	flood_fill(t_game *game, int x, int y, char **valid);
int	flood_check(t_game *game);
int 			read_map(t_game *game, char *file);
int				check_map(t_game *game);
int				error_message(t_game *game, char str);
//int	check_player_exit(t_game *game);
//void			checked_error_game(t_game *game, char *argv);
size_t			lign_map(char *file_lign);
void			move_player(t_game *game, int to_y, int to_x);
void			player_exit_position(t_game *game);
int				is_map_playable(t_game *game);
void			terminate_game(t_game *game);
void			load_images(t_game *game);
void			loves_numbers(t_game *game);
void			update_map(t_game *game, int next_y, int next_x);
int				window_control(t_game *game);
void			image_towindow_size(t_game *game, t_texture *img, int x, int y);

#endif