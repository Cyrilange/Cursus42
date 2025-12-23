/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:10:42 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/31 18:05:13 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_north(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = -1;
	player->plan_x = FOV;
	player->plan_y = 0;
}

static void	init_south(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 1;
	player->plan_x = -FOV;
	player->plan_y = 0;
}

static void	init_east(t_player *player)
{
	player->dir_x = 1;
	player->dir_y = 0;
	player->plan_x = 0;
	player->plan_y = FOV;
}

static void	init_west(t_player *player)
{
	player->dir_x = -1;
	player->dir_y = 0;
	player->plan_x = 0;
	player->plan_y = -FOV;
}

void	init_player(t_player *player, double start_x, double start_y,
		char start)
{
	player->pos_x = start_x;
	player->pos_y = start_y;
	player->move_speed = 0.1;
	player->rot_speed = 0.08;
	if (start == 'N')
		init_north(player);
	else if (start == 'S')
		init_south(player);
	else if (start == 'E')
		init_east(player);
	else if (start == 'W')
		init_west(player);
}
