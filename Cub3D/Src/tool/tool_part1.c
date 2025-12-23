/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_part1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:14:30 by csalamit          #+#    #+#             */
/*   Updated: 2025/11/06 20:05:38 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "./get_next_line/get_next_line_bonus.h"

static void	free_list(t_line *list)
{
	t_line	*tmp;

	while (list)
	{
		tmp = list->next;
		if (list->content)
			free(list->content);
		free(list);
		list = tmp;
	}
}

void	helper_free_game(t_game *game)
{
	if (game->texture.no_path)
		free(game->texture.no_path);
	if (game->texture.so_path)
		free(game->texture.so_path);
	if (game->texture.ea_path)
		free(game->texture.ea_path);
	if (game->texture.we_path)
		free(game->texture.we_path);
	if (game->texture.no)
		mlx_delete_texture(game->texture.no);
	if (game->texture.so)
		mlx_delete_texture(game->texture.so);
	if (game->texture.ea)
		mlx_delete_texture(game->texture.ea);
	if (game->texture.we)
		mlx_delete_texture(game->texture.we);
	if (game->img.img)
		mlx_delete_image(game->mlx, game->img.img);
}

void	free_game(t_game *game)
{
	int	i;

	if (game->map.map)
	{
		i = -1;
		while (++i < game->map.map_height)
		{
			if (game->map.map[i])
				free(game->map.map[i]);
		}
		free(game->map.map);
		game->map.map = NULL;
	}
	helper_free_game(game);
	free_gnl_static();
}

static void	error_exit(t_game *game, t_line *lines, char *line, const char *msg)
{
	if (line)
		free(line);
	if (lines)
		free_list(lines);
	helper_free_game(game);
	free_gnl_static();
	g_error_function(game, msg);
}

void	handle_line_or_exit(t_game *game, char *line, t_line **lines)
{
	if (handle_line(game, line, lines) == ERROR)
	{
		error_exit(game, *lines, line, "Error\n duplicate texture path");
	}
}
