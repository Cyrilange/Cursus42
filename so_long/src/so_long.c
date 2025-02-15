#include "../includes/so_long.h"

static int	ber_file(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if ((file[len - 4] != '.' || file[len - 3] != 'b'
			|| file[len -2] != 'e' || file[len -1] != 'r'))
    {
        ft_printf("Error with the file.ber");
        return (FAIL);
    }
	return (SUCCESS);
}

static t_grid	ft_count_obj(t_map_node *map)
{
	t_grid	obj;
	int		i;

	ft_objs_init(&obj);
	while (map)
	{
		i = 0;
		while (map->map[i])
		{
			if (map->map[i] == PLAYER)
				obj.player++;
			if (map->map[i] == COLLECTIBLE)
				obj.collectible++;
			if (map->map[i] == EXIT)
				obj.exit++;
			i++;
		}
		map = map->next;
	}
	return (obj);
}

void	ft_mlx_init(t_game *game)
{
	game = ft_find_ship(game);
	game->mlx = mlx_init(game->size_pix.x * TILE_SIZE, game->size_pix.y * TILE_SIZE, "so_long", true);
	if (!game || !game->mlx)
	{
		ft_printf("Error with MLX");
		ft_free_all(game, 1);
		exit(FAIL);
	}
	init_textures(game);
	init_images(game);
	read_map(game);
	game->images.player = NULL;
	mlx_key_hook(game->mlx, ft_handle_input, game);
	mlx_loop(game->mlx);
}

int	so_long(char *path)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (FAIL);
	int_game_function(game);
	game->path = path;
	if (ft_map(&game) == 1)
		return (FAIL);
	game = find_player(game);
	game = init_flood_fill(game);
	game->grid_b = ft_free_status(game->grid_b, game->size_pix.y);
	if (error_init_game(game, ft_count_obj(game->map)))
	{
		ft_free_all(game, 1);
		return (FAIL);
	}
	ft_mlx_init(game);
	ft_free_all(game, 0);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		ft_printf("Error");
		return (1);
	}
	if (argc == 2)
	{
		if (ber_file(argv[1]) == FAIL)
		    return (FAIL);
		i = ft_start_map(argv[1]);
		if (i == 1)
			return (FAIL);
	}
	printf("Thanks for playing");
	return (0);
}