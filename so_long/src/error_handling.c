#include "../includes/so_long.h"

void free_game(t_map *game)
{
    mlx_delete_image(game->mlx, game->wall);
    mlx_delete_image(game->mlx, game->floor);
    mlx_delete_image(game->mlx, game->player);
    mlx_delete_image(game->mlx, game->collectible);
    mlx_delete_image(game->mlx, game->exit);
    mlx_terminate(game->mlx);
    free(game);
    ft_printf("GOOD BYE!!!!!");
}