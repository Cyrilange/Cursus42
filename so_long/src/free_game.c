/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-26 17:14:10 by csalamit          #+#    #+#             */
/*   Updated: 2025-02-26 17:14:10 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_message(t_game *game, char str)
{
	ft_printf("\033[33mError\n\033[31m");
	if (str == 'M')
		ft_printf("Invalid map: Issue with map content or structure.\n");
	else if (str == 'P')
		ft_printf("Unplayable map: No valid path found.\n");
	else if (str == 'W')
		ft_printf("Window initialization failed.\n");
	terminate_game(game);
	return (ERROR);
}

static void	delete_images(t_game *game)
{
	if (game->img.floor.i)
		mlx_delete_image(game->mlx, game->img.floor.i);
	if (game->img.wall.i)
		mlx_delete_image(game->mlx, game->img.wall.i);
	if (game->img.player.i)
		mlx_delete_image(game->mlx, game->img.player.i);
	if (game->img.collectable.i)
		mlx_delete_image(game->mlx, game->img.collectable.i);
	if (game->img.exit.i)
		mlx_delete_image(game->mlx, game->img.exit.i);
}

static void	delete_textures(t_game *game)
{
	delete_images(game);
	if (game->img.floor.t)
		mlx_delete_texture(game->img.floor.t);
	if (game->img.wall.t)
		mlx_delete_texture(game->img.wall.t);
	if (game->img.player.t)
		mlx_delete_texture(game->img.player.t);
	if (game->img.collectable.t)
		mlx_delete_texture(game->img.collectable.t);
	if (game->img.exit.t)
		mlx_delete_texture(game->img.exit.t);
}

void	terminate_game(t_game *game)
{
	int	i;

	if (game->file.map)
	{
		i = -1;
		while (++i < game->file.map_height)
		{
			free(game->file.map[i]);
			game->file.map[i] = NULL;
		}
		free(game->file.map);
		game->file.map = NULL;
	}
	delete_textures(game);
	if (game->mlx)
	{
		mlx_terminate(game->mlx);
		game->mlx = NULL;
	}
	ft_memset(game, 0, sizeof(t_game));
}
