/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:14:25 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/28 13:46:47 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static inline void	perform_dda(t_game *game, t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->map_x < 0 || ray->map_x >= game->map.map_width
			|| ray->map_y < 0 || ray->map_y >= game->map.map_height)
		{
			ray->hit = 1;
			break ;
		}
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map.map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

static inline void	calc_wall_distance_and_height(t_player *p, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - p->pos_x + (1 - ray->step_x) / 2)
			/ ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - p->pos_y + (1 - ray->step_y) / 2)
			/ ray->ray_dir_y;
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

static inline void	draw_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			ft_put_pixel(game, x, y, game->texture.ceilling);
			x++;
		}
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			ft_put_pixel(game, x, y, game->texture.floor);
			x++;
		}
		y++;
	}
}

void	raycasting(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	draw_background(game);
	while (x < WIN_WIDTH)
	{
		init_ray(&ray, game, x);
		init_ray_step(&ray, game);
		perform_dda(game, &ray);
		calc_wall_distance_and_height(&game->player, &ray);
		draw_ray_column(game, x, &ray);
		x++;
	}
}
