/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:10:35 by csalamit          #+#    #+#             */
/*   Updated: 2025/11/06 20:01:46 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_map(t_map *map)
{
	map->map = NULL;
	map->map_height = 0;
	map->map_width = 0;
}

void	init_game_struct(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->img.img = NULL;
	init_map(&game->map);
	init_textures(&game->texture);
	game->player.pos_x = 0;
	game->player.pos_y = 0;
	game->player.start_dir = 0;
}
