#include "../includes/so_long.h"

static void player_move(t_map *game, t_dir  direction)
{
/*
if up , x--
down x++
right y++
lefy y--
*/
}

void    key_press(mlx_key_data_t keydata, void *param)
{
    t_map *map = (t_map *)param;

    if (keydata.key == MLX_KEY_ESCAPE)
        mlx_close_window(map->mlx);

    // Déplacer le joueur
    if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
            && keydata.action == MLX_PRESS)
        player_moving();
    else if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
            && keydata.action == MLX_PRESS)
        player_moving();
    else if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
            && keydata.action == MLX_PRESS)
        player_moving();
    else if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
            && keydata.action == MLX_PRESS)
        player_moving();
}
