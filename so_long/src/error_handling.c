#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return;
	i = 0;
	while (map[i])
	{
		free(map[i]); // Libère chaque ligne de la map
		i++;
	}
	free(map); // Libère le tableau de pointeurs
}

void	free_all(t_map *game, int error)
{
	if (error)
	{
		free_map(game->map);  // Appelle la fonction pour libérer la map
		free(game);           // Libère la structure `t_map`
	}
}
