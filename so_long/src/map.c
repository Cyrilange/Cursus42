#include "../includes/so_long.h"

static int	ber_file(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if ((file[len - 4] != '.' || file[len - 3] != 'b'
			|| file[len -2] != 'e' || file[len -1] != 'r'))
		return (FAIL);
	return (SUCCESS);
}

static char	**ft_status_map(t_game *game)
{
	t_game	*tmp;
	char	**status;
	int		i;

	i = 0;
	tmp = game->map;
	status = malloc(sizeof(char *) * (game->size_pix.y + 1));
	if (!status)
		return (NULL);
	while (game->map)
	{
		status[i] = ft_strdup(game->map->map);
		if (!status[i])
		{
			ft_free_status(status, i);
			return (NULL);
		}
		i++;
		game->map = game->map->next;
	}
	game->map = tmp;
	status[i] = NULL;
	return (status);
}

int	ft_map(t_game **game)
{
	t_game	*tmp;

	tmp = *game;
	tmp->map = ft_map_init(tmp);
	if (!tmp->map)
	{
		free(tmp);
		return (1);
	}
	tmp->size_pix.x = ft_map_x(tmp->map);
	tmp->size_pix.y = ft_map_y(tmp->map);
	tmp->grid_y = ft_status_map(tmp);
	if (!tmp->grid_y)
	{
		ft_free_all(tmp, 2);
		return (FAIL);
	}
	tmp->grid_b = ft_status_map(tmp);
	if (!tmp->grid_b)
	{
		ft_free_all(tmp, 1);
		return (FAIL);
	}
	*game = tmp;
	return (SUCCESS);
}