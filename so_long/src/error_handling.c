#include "../includes/so_long.h"

int	error_object(t_grid current, t_grid must_be)
{
	if (current.player != must_be.player)
		return (FAIL);
	if (current.collectible != must_be.collectible)
		return (FAIL);
	if (current.exit != must_be.exit)
		return (FAIL);
	return (0);
}

int	error_object_number(t_grid current)
{
	if (current.player != 1)
		exit(EXIT_FAILURE);
	if (current.collectible < 1)
		exit(EXIT_FAILURE);
	if (current.exit != 1)
		exit(EXIT_FAILURE);
	return (SUCCESS);
}


static int	error_map_rectangle(t_game *game)
{
	int i;
	int j;
	int l_size;

	j = 0;
	l_size = 0;

	// Trouver la taille de la première ligne
	while (game->grid_y[j][l_size] != '\n' && game->grid_y[j][l_size] != '\0')
		l_size++;

	while (j < game->size_pix.y) // Parcourt toutes les lignes
	{
		i = 0;
		while (game->grid_y[j][i] != '\n' && game->grid_y[j][i] != '\0') // Parcours chaque caractère
		{
			if (game->grid_y[j][i] != '0' && game->grid_y[j][i] != WALL
				&& game->grid_y[j][i] != PLAYER && game->grid_y[j][i] != COLLECTIBLE
				&& game->grid_y[j][i] != EXIT)
				return (1);  // Erreur si caractère invalide
			i++;
		}
		// Vérifie si la longueur de la ligne est la même que la première
		if (l_size != i)
			return (FAIL);
		j++;
	}
	return (0);
}


static int	error_wall(t_game *game)
{
	int i;
	int j;

	j = 0;
	while (j < game->size_pix.y)
	{
		i = 0;
		while (game->grid_y[j][i] != '\n' && game->grid_y[j][i] != '\0')
		{
			if (j == 0 && game->grid_y[j][i] != WALL) // Première ligne
				return (-1);
			if (j == game->size_pix.y - 1 && game->grid_y[j][i] != WALL) // Dernière ligne
				return (-1);
			if (j != 0 && (i == 0 || i == game->size_pix.x - 1) && game->grid_y[j][i] != WALL) // Bordures intermédiaires
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

int	error_init_game(t_game *game, t_grid objects)
{
	int	x;

	x = SUCCESS;
	if (error_object_number(objects) == FAIL)
		x = FAIL;
	if (error_object(game->grid, objects) == FAIL)
		x = FAIL;
	if (error_map_rectangle(game) == FAIL)
		x = FAIL;
	if (error_wall(game) == FAIL)
		x = FAIL;
	if (x == FAIL)
	{
		ft_printf("ERROR");
		exit(EXIT_FAILURE);
		return (FAIL);
	}
	return (SUCCESS);
}