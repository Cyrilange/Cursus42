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
		return (0);
	else if (valid[y][x] == '1')
		return (0);
	else if (valid[y][x] == 'C')
		loves++;
	else if (valid[y][x] == 'E')
		exit_flag = true;
	valid[y][x] = '1';

	// Appels récursifs
	flood_fill(game, x + 1, y, valid);
	flood_fill(game, x - 1, y, valid);
	flood_fill(game, x, y + 1, valid);
	flood_fill(game, x, y - 1, valid);
	return (1);
}

static char	**init_map(t_game *game)
{
	int		i;
	char	**copy_map;

	copy_map = ft_calloc((game->file.map_height + 1), sizeof(char *));
	if (!copy_map)
		return (NULL);
	
	i = 0;
	while (i < game->file.map_height)
	{
		copy_map[i] = ft_strdup(game->file.map[i]);
		if (!copy_map[i])  // Si l'allocation échoue, on libère tout et on retourne NULL
		{
			free_map(copy_map);
			return (NULL);
		}
		i++;
	}
	return (copy_map);
}

int	flood_check(t_game *game)
{
	char	**valid;

	valid = init_map(game);
	if (!valid)
		return (1); // Erreur d'allocation mémoire

	if (!flood_fill(game, game->position.player_x_pos, game->position.player_y_pos, valid))
	{
		free_map(valid);
		return (1);
	}
	free_map(valid);
	return (0);
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
