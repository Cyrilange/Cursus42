#include "../includes/so_long.h"

static void	free_map(char **map)
{
	int	i;

	if (!map)
		return;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	flood_fill(t_game *game, int x, int y, char **valid)
{
	static int	loves = 0;
	static bool	exit_flag = false;

	if (x < 0 || y < 0 || x >= game->file.map_width || y >= game->file.map_height)
		return (ERROR);
	if (valid[y][x] == '1') // Case déjà visitée ou mur
		return (ERROR);
	if (valid[y][x] == 'C')
		loves++;
	if (valid[y][x] == 'E')
		exit_flag = true;

	valid[y][x] = '1'; // Marquer la case comme visitée

	// Vérifier si un des appels récursifs retourne SUCCESS
	if (flood_fill(game, x + 1, y, valid) == SUCCESS ||
		flood_fill(game, x - 1, y, valid) == SUCCESS ||
		flood_fill(game, x, y + 1, valid) == SUCCESS ||
		flood_fill(game, x, y - 1, valid) == SUCCESS)
		return (SUCCESS);

	// Vérifier si on a atteint toutes les conditions de victoire
	if (loves == game->count.n_loves && exit_flag == true)
		return (SUCCESS);

	return (ERROR);
}


static char	**init_map(t_game *game)
{
	{
		int		i;
		char	**check_map;
	
		i = -1;
		check_map = ft_calloc((game->file.map_height + 1), sizeof(char *));
		while (++i < game->file.map_height)
			check_map[i] = ft_strdup(game->file.map[i]);
		return (check_map);
	}
}

int	flood_check(t_game *game)
{
	char	**valid;

	valid = init_map(game);
	if (!valid)
		return (ERROR); // Erreur d'allocation mémoire

	// Si flood_fill retourne SUCCESS, on retourne aussi SUCCESS
	if (flood_fill(game, game->position.player_x_pos, game->position.player_y_pos, valid) == SUCCESS)
	{
		free_map(valid);
		return (SUCCESS);
	}

	free_map(valid);
	return (ERROR);
}





int	is_map_playable(t_game *game)
{
	int	i;

	i = -1;
	while (game->file.map[++i])
	{
		if (lign_map(game->file.map[i]) != (size_t)game->file.map_width)
			return (1);
		if (ft_strchr(game->file.map[i], 'P'))
			game->count.n_player++;
		if (ft_strchr(game->file.map[i], 'E'))
			game->count.n_exit++;
	}
	loves_numbers(game);
	if (game->count.n_loves < 1)
		return (1);
	if (game->count.n_player != 1 || game->count.n_exit != 1)
		return (1);
	return (0);
}
