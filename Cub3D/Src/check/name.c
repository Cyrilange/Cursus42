/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:10:12 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/29 14:21:00 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_cell(t_wall_ctx *ctx)
{
	char	**map;
	int		y;
	int		x;
	int		line_len;

	map = ctx->game->map.map;
	y = ctx->y;
	x = ctx->x;
	line_len = ctx->line_len;
	if (map[y][x] != '0')
		return ;
	if (y == 0 || x == 0 || y == ctx->game->map.map_height - 1
		|| x == line_len - 1
		|| (y > 0 && x >= (int)ft_strlen(map[y - 1])) || map[y - 1][x] == ' '
		|| (y < ctx->game->map.map_height - 1 && x
			>= (int)ft_strlen(map[y + 1])) || map[y + 1][x] == ' '
		|| (x - 1 >= 0 && map[y][x - 1] == ' ')
		|| (x + 1 < line_len && map[y][x + 1] == ' '))
	{
		g_error_function(ctx->game, "Error: map not closed");
	}
}

int	check_wall(t_game *game)
{
	int			y;
	int			x;
	int			line_len;
	t_wall_ctx	ctx;

	ctx.game = game;
	y = 0;
	while (y < game->map.map_height)
	{
		line_len = (int)ft_strlen(game->map.map[y]);
		x = 0;
		while (x < line_len)
		{
			ctx.y = y;
			ctx.x = x;
			ctx.line_len = line_len;
			check_cell(&ctx);
			x++;
		}
		y++;
	}
	return (0);
}

void	check_name(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(&file[len - 4], ".cub", 4) != 0)
		error_function("Error: Invalid file name. Expected a .cub file\n");
}
