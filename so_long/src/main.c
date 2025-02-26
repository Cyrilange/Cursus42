/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-26 17:14:35 by csalamit          #+#    #+#             */
/*   Updated: 2025-02-26 17:14:35 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_exit_position(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->file.map[++i])
	{
		j = -1;
		while (game->file.map[i][++j])
		{
			if (game->file.map[i][j] == 'P')
			{
				game->position.player_x_pos = j;
				game->position.player_y_pos = i;
			}
			else if (game->file.map[i][j] == 'E')
			{
				game->position.exit_x_pos = j;
				game->position.exit_y_pos = i;
			}
		}
	}
}

static void	init_count(t_game *game)
{
	game->count.moves = 0;
	game->count.n_loves = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	system("clear");
	ft_memset(&game, 0, sizeof(t_game));
	ft_printf("\033[94m");
	if (argc != 2)
		return (ft_printf("Error\nProvide a valid map file\n"), ERROR);
	init_count(&game);
	if (read_map(&game, argv[1]) == ERROR)
		return (error_message(&game, 'M'), ERROR);
	if (check_map(&game) == ERROR)
		return (error_message(&game, 'M'), ERROR);
	if (flood_check(&game) == ERROR)
		return (error_message(&game, 'P'), ERROR);
	if (window_control(&game) == ERROR)
		return (error_message(&game, 'W'), ERROR);
	terminate_game(&game);
	ft_printf("\033[0m");
	return (SUCCESS);
}
