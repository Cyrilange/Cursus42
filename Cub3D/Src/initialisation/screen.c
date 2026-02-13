/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:13:57 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/29 20:43:20 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_window(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3D", true);
	if (!game->mlx)
	{
		error_function("Error\n Failed to initialize window\n");
	}
}

void	load_textures(t_game *game)
{
	if (!game->texture.no_path || !game->texture.so_path
		|| !game->texture.we_path || !game->texture.ea_path)
		g_error_function(game, "Error\n missing texture path(s)");
	game->texture.no = mlx_load_png(game->texture.no_path);
	game->texture.so = mlx_load_png(game->texture.so_path);
	game->texture.ea = mlx_load_png(game->texture.ea_path);
	game->texture.we = mlx_load_png(game->texture.we_path);
	if (!game->texture.no || !game->texture.so
		|| !game->texture.ea || !game->texture.we)
	{
		g_error_function(game, "Error\n failed to load textures");
	}
}

void	init_ray(t_ray *ray, t_game *game, int x)
{
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = game->player.dir_x + game->player.plan_x * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.plan_y * ray->camera_x;
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void	init_ray_step(t_ray *ray, t_game *game)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y)
			* ray->delta_dist_y;
	}
}
