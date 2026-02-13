/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-26 17:13:02 by csalamit          #+#    #+#             */
/*   Updated: 2025-02-26 17:13:02 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
			return (ERROR);
		if (game->file.map[i][game->file.map_width - 1] != '1')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	check_map(t_game *game)
{
	if (!game->file.map)
		return (ERROR);
	game->file.map_width = lign_map(game->file.map[0]);
	if (check_wall(game) || init_checks(game)
		|| is_map_playable(game))
		return (ERROR);
	player_exit_position(game);
	return (SUCCESS);
}
