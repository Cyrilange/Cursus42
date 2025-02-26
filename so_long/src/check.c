#include "../includes/so_long.h"

void	image_towindow_size(t_game *game, t_texture *img, int x, int y)
{
	mlx_image_to_window(game->mlx, game->img.floor.i, WIDTH * x, HEIGHT * y);
	mlx_image_to_window(game->mlx, img->i, WIDTH * x, HEIGHT * y);
	img->i->enabled = 1;
}

static void	init_window(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->file.map[++i])
	{
		j = -1;
		while (game->file.map[i][++j])
		{
			if (game->file.map[i][j] == '1')
				image_towindow_size(game, &game->img.wall, j, i);
			else if (game->file.map[i][j] == '0')
				image_towindow_size(game, &game->img.floor, j, i);
			else if (game->file.map[i][j] == 'P')
				image_towindow_size(game, &game->img.player, j, i);
			else if (game->file.map[i][j] == 'E')
				image_towindow_size(game, &game->img.exit, j, i);
			else if (game->file.map[i][j] == 'C')
				image_towindow_size(game, &game->img.collectable, j, i);
		}
	}
}

static void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		ft_printf("You escaped the game\nSee you!!!!\n");
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(game, -1, 0);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(game, 0, -1);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(game, +1, 0);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(game, 0, +1);
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		ft_printf("There is %i loves to pick up!\n", game->count.n_loves);
}

int	window_control(t_game *game)
{
	int	window_width;
	int	window_height;

	window_width = WIDTH * game->file.map_width;
	window_height = HEIGHT * game->file.map_height;
	if (window_width > 1920)
		window_width = 1920;
	if (window_height > 1080)
		window_height = 1080;
	game->window_size.max_width = window_width / WIDTH;
	game->window_size.max_height = window_height / HEIGHT;
	game->mlx = mlx_init(window_width, window_height, "so_long", false);
	if (!game->mlx)
	{
		terminate_game(game);
		return (ERROR);
	}
	load_images(game);
	init_window(game);
	mlx_key_hook(game->mlx, &ft_keyhook, game);
	mlx_loop(game->mlx);
	return (SUCCESS);
}

void	loves_numbers(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->file.map[++i])
	{
		j = -1;
		while (game->file.map[i][++j])
		{
			if (game->file.map[i][j] == 'C')
				game->count.n_loves++;
		}
	}
}
