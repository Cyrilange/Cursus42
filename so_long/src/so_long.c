#include "../includes/so_long.h"

#include "../includes/so_long.h"

void init_player_position(t_map *game)
{
	int32_t	y;
	int32_t	x;
	ft_printf("fonction pour trouver le joueur");
	y = 0;
    while (y < game->height)  // Parcours des lignes (y)
    {
		x = 0;
        while (x < game->width)  // Parcours des colonnes (x)
        {
            if (game->grid[y][x] == 'P')  // Si on trouve 'P'
            {
                game->player_coord.x = x;  // Stocke la position X
                game->player_coord.y = y;  // Stocke la position Y
				ft_printf("Position du joueur initialisée à : (%d, %d)\n", x, y);
                return;  // On arrête la recherche dès qu'on trouve le joueur
            }
			x++;
        }
		y++;
    }
	 printf("Erreur : joueur non trouvé sur la carte !\n");
}

int main(int argc, char **argv)
{
    t_map game;
    if (argc != 2)
    {
        fprintf(stderr, "Erreur : usage incorrect.\n");
        fprintf(stderr, "Utilisation : ./so_long <map.ber>\n");
        return (EXIT_FAILURE);
    }
	
    init_game(&game, argv[1]);
	init_player_position(&game);

    
    load_textures(&game);
    display_map(&game);
    mlx_key_hook(game.mlx, key_press, &game);
    mlx_loop(game.mlx);
	free_game(&game);

    return (EXIT_SUCCESS);
}
