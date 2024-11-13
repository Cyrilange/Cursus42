#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "./printf/ft_printf.h"
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"
#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"

typedef struct s_data_game
{
    void	*mlx;
    void	*win;
    void	*floor_img;
    void	*wall_img;
    int		img_width;
    int		img_height;
    char	**map;
    int		map_width;
	int		map_height;
} t_data_game;

#endif