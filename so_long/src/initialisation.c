#include "../includes/so_long.h"

int ft_strlen_so(char *str)
{
    int i = 0;
    if (str == NULL) {  // Handle NULL input!
        return 0;
    }
    while (str[i] && str[i] != '\n')
        i++;
    return (i);
}

t_game *init_game(t_game *game, char *map_file)
{
    // Allocation mémoire pour la structure t_game
    game = malloc(sizeof(t_game));
    if (!game)
    {
        ft_printf("Erreur : impossible d'initialiser le jeu.\n");
        exit(EXIT_FAILURE);
    }

    // Initialisation de MLX
    game->mlx = mlx_init(1280, 640, "so_long", false);
    if (!game->mlx)
    {
        ft_printf("Problème lors de l'initialisation de MLX\n");
        free(game);  // Libération de la mémoire allouée si MLX échoue
        exit(EXIT_FAILURE);
    }

    // Lecture de la carte
    game->map = read_map(map_file);
    if (!game->map)
    {
        ft_printf("Erreur de lecture de la carte\n");
        free(game);  // Libération de la mémoire allouée si la lecture échoue
        exit(EXIT_FAILURE);
    }
/*
    // Comptage des lignes et des colonnes de la carte
    game->map->height = count_line(map_file);
    game->map->width = ft_strlen_so(game->map->grid[0]); // Correction : accéder à game->map->grid
*/
    // Initialisation de la position du joueur
    init_player_position(game);

    // Affichage d'un message pour vérifier l'initialisation
    ft_printf("Jeu initialisé avec succès !\n");

    return game;
}
