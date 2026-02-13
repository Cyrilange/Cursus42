/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:40:17 by csalamit          #+#    #+#             */
/*   Updated: 2025/11/06 20:09:16 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	handle_player(t_game *g, int x, int y, t_player_ctx *ctx)
{
	char	c;

	c = g->map.map[y][x];
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (ctx->found++)
			g_error_function(g, "Error: multiple player starts in map");
		*ctx->s_x = x + 0.5;
		*ctx->s_y = y + 0.5;
		*ctx->start_dir = c;
		g->map.map[y][x] = '0';
	}
}

void	find_player(t_game *g, double *s_x, double *s_y, char *start_dir)
{
	int				y;
	int				x;
	int				line_len;
	t_player_ctx	ctx;

	ctx.s_x = s_x;
	ctx.s_y = s_y;
	ctx.start_dir = start_dir;
	ctx.found = 0;
	y = 0;
	while (y < g->map.map_height)
	{
		line_len = (int)ft_strlen(g->map.map[y]);
		x = 0;
		while (x < line_len)
		{
			handle_player(g, x, y, &ctx);
			x++;
		}
		y++;
	}
	if (!ctx.found)
		g_error_function(g, "Error: no player found in map");
}

void	close_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_game(game);
	if (game->mlx)
	{
		if (game->mlx->window)
			mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	g;

	if (ac != 2)
		error_function("Usage: ./cub3D <map.cub>");
	check_name(av[1]);
	init_game_struct(&g);
	parse_map_file(av[1], &g);
	check_wall(&g);
	find_player(&g, &g.player.pos_x, &g.player.pos_y, &g.player.start_dir);
	init_player(&g.player, g.player.pos_x, g.player.pos_y, g.player.start_dir);
	load_textures(&g);
	init_window(&g);
	g.img.img = mlx_new_image(g.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!g.img.img || mlx_image_to_window(g.mlx, g.img.img, 0, 0) < 0)
		error_function("Error: image buffer failed");
	mlx_loop_hook(g.mlx, game_loop, &g);
	mlx_close_hook(g.mlx, close_game, &g);
	mlx_loop(g.mlx);
}
