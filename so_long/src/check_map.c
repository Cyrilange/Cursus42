#include "../includes/so_long.h"

static int	ft_count_char(const char *str, char c)
{
	int	count = 0;

	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

static int	init_checks(t_game *game)
{
	const char	*str_map = "10PCE\n";
	int			i;
	int			j;

	i = 0;
	while (game->file.map[i])
	{
		j = 0;
		while (game->file.map[i][j])
		{
			if (!ft_strchr(str_map, game->file.map[i][j]))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	check_player_exit(t_game *game)
{
	int	i;

	i = 0;
	game->count.n_player = 0;
	game->count.n_exit = 0;
	game->count.n_loves = 0;

	while (game->file.map[i])
	{
		if (lign_map(game->file.map[i]) != (size_t)game->file.map_width)
			return (1);
		game->count.n_player += ft_count_char(game->file.map[i], 'P');
		game->count.n_exit += ft_count_char(game->file.map[i], 'E');
		game->count.n_loves += ft_count_char(game->file.map[i], 'C');
		i++;
	}
	return (game->count.n_player != 1 || game->count.n_exit != 1
		|| game->count.n_loves < 1);
}

static int	check_wall(t_game *game)
{
	int	i;

	i = 0;
	if (ft_strchr(game->file.map[0], '0'))
		return (1);
	if (ft_strchr(game->file.map[game->file.map_height - 1], '0'))
		return (1);
	while (game->file.map[i])
	{
		if (game->file.map[i][0] != '1')
			return (1);
		if (game->file.map[i][game->file.map_width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_map(t_game *game)
{
	if (!game->file.map)
    	return (ERROR);
	game->file.map_width = lign_map(game->file.map[0]);
	if (check_player_exit(game) || check_wall(game) || init_checks(game)
		|| is_map_playable(game))
		return (ERROR);
	player_exit_position(game);
	return (SUCCESS);
}
