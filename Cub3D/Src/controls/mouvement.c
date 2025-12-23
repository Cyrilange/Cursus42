/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:10:30 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/29 14:50:39 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_wall(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_y = (int)y;
	map_x = (int)x;
	if (map_y < 0 || map_y >= game->map.map_height)
		return (1);
	if (map_x < 0 || map_x >= (int)ft_strlen(game->map.map[map_y]))
		return (1);
	return (game->map.map[map_y][map_x] != '0');
}

void	try_move(t_game *game, double dx, double dy)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + dx;
	new_y = game->player.pos_y + dy;
	if (!is_wall(game, new_x + COLLISION_MARGIN, game->player.pos_y)
		&& !is_wall(game, new_x - COLLISION_MARGIN, game->player.pos_y)
		&& !is_wall(game, new_x, game->player.pos_y + COLLISION_MARGIN)
		&& !is_wall(game, new_x, game->player.pos_y - COLLISION_MARGIN))
		game->player.pos_x = new_x;
	if (!is_wall(game, game->player.pos_x, new_y + COLLISION_MARGIN)
		&& !is_wall(game, game->player.pos_x, new_y - COLLISION_MARGIN)
		&& !is_wall(game, game->player.pos_x + COLLISION_MARGIN, new_y)
		&& !is_wall(game, game->player.pos_x - COLLISION_MARGIN, new_y))
		game->player.pos_y = new_y;
}

static void	rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_angle;
	double	sin_angle;

	old_dir_x = player->dir_x;
	old_plane_x = player->plan_x;
	cos_angle = cos(angle);
	sin_angle = sin(angle);
	player->dir_x = player->dir_x * cos_angle - player->dir_y * sin_angle;
	player->dir_y = old_dir_x * sin_angle + player->dir_y * cos_angle;
	player->plan_x = player->plan_x * cos_angle - player->plan_y * sin_angle;
	player->plan_y = old_plane_x * sin_angle + player->plan_y * cos_angle;
}

void	rotate_left(t_player *player)
{
	rotate_player(player, player->rot_speed);
}

void	rotate_right(t_player *player)
{
	rotate_player(player, -player->rot_speed);
}
