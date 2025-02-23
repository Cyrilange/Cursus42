#include "../includes/so_long.h"

void	player_exit_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->file.map[i])
	{
		j = 0;
		while (game->file.map[i][j])
		{
			if (game->file.map[i][j] == 'P')
			{
				game->position.player_x_pos = j;
				game->position.player_y_pos = i;
			}
			if (game->file.map[i][j] == 'E')
			{
				game->position.exit_x_pos = j;
				game->position.exit_y_pos = i;
			}
			j++;
		}
		i++;
	}
}

static void	init_count(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->count.moves = 0;
	game->count.n_loves = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;
	system("clear");
	ft_printf("\033[94m");
	if (argc == 1 || argc > 2)
		return (ft_printf("Error\nYou need to provide the Map, it should be the onlys args provided\n"));
	init_count(&game);
	if (argc == 2)
	{
		if (read_map(&game, argv[1]) || check_map(&game))
			return (error_message(&game, 'M'));
		else if (flood_check(&game))
			return(error_message(&game, 'P'));
		else if (window_control(&game))
			return(error_message(&game, 'W'));
	}
	terminate_game(&game);
	ft_printf("\033[0m");
	return (0);
}