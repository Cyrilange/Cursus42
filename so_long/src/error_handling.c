#include "../includes/so_long.h"

void free_game(t_game *game)
{
    mlx_delete_image(game->mlx, game->wall);
    mlx_delete_image(game->mlx, game->floor);
    mlx_delete_image(game->mlx, game->player);
    mlx_delete_image(game->mlx, game->collectible);
    mlx_delete_image(game->mlx, game->exit);

    // Libérer la mémoire allouée pour la carte
    if (game->map)
    {
        // Libérer la grille de la carte
        for (int i = 0; i < game->map->height; i++)
        {
            free(game->map->grid[i]);
        }
        free(game->map->grid);
        free(game->map);
    }

    mlx_terminate(game->mlx);
    free(game);
    ft_printf("GOOD BYE!!!!!\n");
}
