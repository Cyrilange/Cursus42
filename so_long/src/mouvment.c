#include "../includes/so_long.h"

void move_player(t_map *game, int new_x, int new_y)
{
    // Si c'est un mur ('1'), on ne bouge pas
    if (game->map[new_y][new_x] == '1')
        return;

    // Si on ramasse un collectible ('C'), on met à jour le compteur
    if (game->map[new_y][new_x] == 'C')
        game->collectibles--;

    // Si on atteint la sortie ('E') mais qu'il reste des collectibles, on ne sort pas
    if (game->map[new_y][new_x] == 'E' && game->collectibles != 0)
    {
        printf("Il reste encore des collectibles !\n");
        return;
    }
    else if (game->map[new_y][new_x] == 'E' && game->collectibles == 0)
    {
        printf("Bravo ! Vous avez terminé le jeu !\n");
        exit(EXIT_SUCCESS);
    }

    // Mise à jour du tableau de la map
    game->map[game->player_pos.y][game->player_pos.x] = '0'; // Ancienne position
    game->map[new_y][new_x] = 'P'; // Nouvelle position

    // Mise à jour des coordonnées du joueur
    game->player_pos.x = new_x;
    game->player_pos.y = new_y;

    // Rafraîchir l'affichage
    render_game(game);
}

void key_press(void *param)
{
    t_map *game = param;
    int new_x = game->player_pos.x;
    int new_y = game->player_pos.y;

    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(game->mlx);
    else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
        new_y--;
    else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
        new_y++;
    else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
        new_x--;
    else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
        new_x++;

    move_player(game, new_x, new_y);
}
