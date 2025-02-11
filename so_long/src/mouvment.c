#include "../includes/so_long.h"

static void player_moving(t_game *game, t_dir direction)
{
    int new_x;
    int new_y;
    char next_tile;

    // Récupère les coordonnées du joueur
    new_x = game->map->player_coord.x;
    new_y = game->map->player_coord.y;

    // Vérification des limites de la carte
    if (new_x < 0 || new_x >= game->map->height || new_y < 0 || new_y >= game->map->width)
        return;

    // Déplacement du joueur selon la direction
    if (direction == UP)
        new_x--;
    else if (direction == DOWN)
        new_x++;
    else if (direction == LEFT)
        new_y--;
    else if (direction == RIGHT)
        new_y++;

    // Vérification de la case suivante
    next_tile = game->map->grid[new_x][new_y];
    if (next_tile == '1')  // Mur
        return;
    if (next_tile == 'C')  // Collectible
        game->map->grid[new_x][new_y] = '0';
    if (next_tile == 'E')  // Sortie
    {
        // Optionnel : Vérifier si tous les collectibles ont été pris avant de gagner
        mlx_close_window(game->mlx);
        return;
    }

    // Met à jour la position du joueur sur la carte
    game->map->grid[game->map->player_coord.x][game->map->player_coord.y] = '0';
    game->map->grid[new_x][new_y] = 'P';
    game->map->player_coord.x = new_x;
    game->map->player_coord.y = new_y;
}

void key_press(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;

    // Gestion de la touche ESC pour fermer la fenêtre
    if (keydata.key == MLX_KEY_ESCAPE)
        mlx_close_window(game->mlx);

    // Gestion des touches de déplacement
    if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
            && keydata.action == MLX_PRESS)
        player_moving(game, UP);
    else if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
            && keydata.action == MLX_PRESS)
        player_moving(game, DOWN);
    else if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
            && keydata.action == MLX_PRESS)
        player_moving(game, LEFT);
    else if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
            && keydata.action == MLX_PRESS)
        player_moving(game, RIGHT);
}
