/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-26 17:14:56 by csalamit          #+#    #+#             */
/*   Updated: 2025-02-26 17:14:56 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	event_checker(t_game *game, int y, int x)
{
	if (game->file.map[y][x] == '1')
		return (ERROR);
	if (game->file.map[y][x] == 'C')
		game->count.n_loves--;
	if (game->file.map[y][x] == 'E' && game->count.n_loves != 0)
		return (1);
	if (game->file.map[y][x] == 'E' && game->count.n_loves == 0)
	{
		ft_printf("the game is finished with %i moves!\n",
			game->count.moves + 1);
		mlx_close_window(game->mlx);
		return (ERROR);
	}
	return (SUCCESS);
}

void	move_player(t_game *game, int to_y, int to_x)
{
	game->dir.y = 0;
	while (game->file.map[game->dir.y])
	{
		game->dir.x = 0;
		while (game->file.map[game->dir.y][game->dir.x])
		{
			if (game->file.map[game->dir.y][game->dir.x] == 'P')
			{
				if (!event_checker(game, game->dir.y
						+ to_y, game->dir.x + to_x))
				{
					update_map(game, game->dir.y + to_y, game->dir.x + to_x);
					game->count.moves++;
					ft_printf("Mouvement %i   \n", game->count.moves);
					return ;
				}
			}
			game->dir.x++;
		}
		game->dir.y++;
	}
}
