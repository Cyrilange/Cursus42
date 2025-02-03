#include "../includes/so_long.h"

void	free_map(char **map)
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

void	free_all(t_map *game, int error)
{
	if (error)
	{
		free_map(game->map);
		free(game);
	}
}
