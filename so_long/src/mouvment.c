#include "../includes/so_long.h"

static t_game	**ft_check_grid(t_game	**game, char check)
{
	if (check == 'C')
	{
		(*game)->grid.collectible++;
		(*game)->collect_taken++;
	}
	if (check == 'P')
		(*game)->grid.player++;
	if (check == 'E')
		(*game)->grid.exit++;
	return (game);
}

static t_dir	ft_check_keypress(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		return (EXIT_GAME);
	if (game->player.y > 0 && game->grid_y[game->player.y - 1][game->player.x] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_UP))
		return (MOVE_UP);
	if (game->player.y < game->size_pix.y - 1 && game->grid_y[game->player.y + 1][game->player.x] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		return (MOVE_DOWN);
	if (game->player.x > 0 && game->grid_y[game->player.y][game->player.x - 1] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		return (MOVE_LEFT);
	if (game->player.x < game->size_pix.x - 1 && game->grid_y[game->player.y][game->player.x + 1] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		return (MOVE_RIGHT);
	return (NO_ACTION);
}

// Gère les entrées utilisateur et applique les déplacements valides
void	ft_handle_input(t_game *game)
{
	t_action action = ft_check_keypress(game);

	if (action == MOVE_UP)
		ft_move_player(game, -1, 0, UP);
	else if (action == MOVE_DOWN)
		ft_move_player(game, 1, 0, DOWN);
	else if (action == MOVE_LEFT)
		ft_move_player(game, 0, -1, LEFT);
	else if (action == MOVE_RIGHT)
		ft_move_player(game, 0, 1, RIGHT);
	else if (action == EXIT_GAME)
		mlx_close_window(game->mlx);
}

void ft_move_player(t_game *game, int move_y, int move_x, t_dir direction)
{
    int new_y;
    int new_x;
    t_coord coord;

    new_y = game->player.y + move_y;
    new_x = game->player.x + move_x;

    if (game->grid_y[new_y][new_x] == WALL)
        return ;
    if (game->grid_y[new_y][new_x] == COLLECTIBLE)
        game->collect_taken++;
    if (game->grid_y[new_y][new_x] == EXIT)
    {
        if (game->collect_taken == game->grid.collectible)
            mlx_close_window(game->mlx);
        return ;
    }

    game->grid_y[game->player.y][game->player.x] = FLOOR;
    game->grid_y[new_y][new_x] = PLAYER;
    game->player.y = new_y;
    game->player.x = new_x;
    game->mouv++;
    game->direction_player = direction;

    coord.y = new_y;
    coord.x = new_x;
    ft_drawing_imgs(game, FLOOR, (t_coord){new_y - move_y, new_x - move_x});
    ft_drawing_imgs(game, PLAYER, coord);
}




void	ft_game_loop(void *param)
{
	t_game *game = (t_game *)param;
	ft_move_player(game);
}

