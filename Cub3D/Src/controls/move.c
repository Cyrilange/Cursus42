/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:51:02 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/29 20:51:08 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_game *game)
{
	try_move(game, game->player.dir_x * game->player.move_speed,
		game->player.dir_y * game->player.move_speed);
}

void	move_backward(t_game *game)
{
	try_move(game, -game->player.dir_x * game->player.move_speed,
		-game->player.dir_y * game->player.move_speed);
}

void	move_left(t_game *game)
{
	if (game->player.dir_x == 0)
		try_move(game,
			game->player.dir_y * game->player.move_speed,
			-game->player.dir_x * game->player.move_speed);
	else
		try_move(game,
			game->player.dir_y * game->player.move_speed,
			-game->player.dir_x * game->player.move_speed);
}

void	move_right(t_game *game)
{
	if (game->player.dir_x == 0)
		try_move(game,
			-game->player.dir_y * game->player.move_speed,
			game->player.dir_x * game->player.move_speed);
	else
		try_move(game,
			-game->player.dir_y * game->player.move_speed,
			game->player.dir_x * game->player.move_speed);
}
