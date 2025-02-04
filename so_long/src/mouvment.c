#include "../includes/so_long.h"

static void player_moving(t_map *game, t_dir direction)
{
    int new_x;
    int new_y;
    char next_tile;

    new_x = game->player_coord.x;
    new_y = game->player_coord.y;
    if (direction == UP)
        new_x--;
    else if (direction == DOWN)
        new_x++;
    else if (direction == LEFT)
        new_y--;
    else if (direction == RIGHT)
        new_y++;
    next_tile = game->grid[new_x][new_y];
    if (next_tile == '1')
        return;
    if (next_tile == 'C')
        game->grid[new_x][new_y] = '0';
    if (next_tile == 'E')
    {
        // (Optionnel : Vérifier si tous les collectibles ont été pris avant de gagner)
        mlx_close_window(game->mlx);
        return;
    }
    game->grid[game->player_coord.x][game->player_coord.y] = '0';
    game->grid[new_x][new_y] = 'P';
    game->player_coord.x = new_x;
    game->player_coord.y = new_y;
}


void    key_press(mlx_key_data_t keydata, void *param)
{
    t_map *map = (t_map *)param;

    if (keydata.key == MLX_KEY_ESCAPE)
        mlx_close_window(map->mlx);
    if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
            && keydata.action == MLX_PRESS)
        player_moving(map, UP);
    else if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
            && keydata.action == MLX_PRESS)
        player_moving(map, DOWN);
    else if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
            && keydata.action == MLX_PRESS)
        player_moving(map, LEFT);
    else if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
            && keydata.action == MLX_PRESS)
        player_moving(map, RIGHT);
}
