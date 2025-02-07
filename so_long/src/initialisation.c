#include "../includes/so_long.h"

int ft_strlen_so(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


t_map *init_game(t_map *game, char *map_file)
{


    // Allocation mémoire pour la structure t_map
    game = malloc(sizeof(t_map));
    if (!game)
		ft_printf("Erreur : impossible d'ouvrir le fichier %s\n", map_file);
        exit(EXIT_FAILURE);

    // Initialisation de MLX
    game->mlx = mlx_init(WIDHT, HEIGHT, "so_long", false);
    if (!game->mlx)
    {
        ft_printf("Problème lors de l'initialisation de MLX\n");
        free(game);  // On libère la mémoire allouée si MLX échoue
        exit(EXIT_FAILURE);
    }

    // Lecture de la carte
    read_map(map_file);
    if (!game->grid) {
        ft_printf("Erreur de lecture de la carte\n");
        free(game);  // Libération de la mémoire allouée si la lecture échoue
        exit(EXIT_FAILURE);
    }

    // Comptage des lignes et des colonnes de la carte
    game->height = count_line(map_file);
    game->width = ft_strlen_so(game->grid[0]); // Supposons que la première ligne soit correctement remplie

    // Initialisation de la position du joueur
    init_player_position(game);

    // Affichage d'un message pour vérifier l'initialisation
    ft_printf("Jeu initialisé avec succès !\n");

    return game;
}


void load_textures(t_map *game)
{
	mlx_texture_t *texture;
	texture = mlx_load_png("./includes/images/wall.png");
	game->wall = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./includes/images/floor.png");
	game->floor = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./includes/images/player.png");
	game->player = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./includes/images/collectible.png");
	game->collectible = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./includes/images/exit.png");
	game->exit = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}
