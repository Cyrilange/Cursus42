
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


# define TS 32

////////////////////
// struct : point //
////////////////////

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

////////////////////
// struct : data  //
////////////////////

typedef struct s_data
{
	char	**map;
	void	*wall;
	void	*empty;
	void	*object;
	void	*player;
	void	*exit;
	void	*mlx;
	void	*win;
	int		count_move;
	int		count_star;
	int		total_star;
	t_point	exit_position;
}			t_data;

typedef struct s_count
{
	int		c;
	int		e;
	int		p;
}			t_count;

void		cleanup(t_data *data);
char		**ft_free_map(char **map);
void		ft_check_fd(int fd);
void		ft_error_map_init(void);
void		load_images(t_data *params);
void		init_window(t_data *params, char **argv);
void		render_map(t_data *game);
void        exit_map(t_data *game);
int			exit_hook(void *params);
t_point		ft_locate(char **map, char c);

int			key_press(int keycode, void *param);

int			ft_count_char(char **map, char c);
int			main_extension(char **argv);

size_t		ft_count_line(char **argv);
char		**ft_map(char **argv);
char		**ft_check_map(char **map, char **argv);

#endif