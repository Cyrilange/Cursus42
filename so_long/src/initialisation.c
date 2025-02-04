#include "../includes/so_long.h"

int ft_strlen_so(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}




t_map *init_game(t_map *game, char *map_file)
{
	game = malloc(sizeof(t_map));
	if (!game)
		exit(EXIT_FAILURE);
	game->mlx = mlx_init(WIDHT, HEIGHT, "so_long", false);
	if (!game->mlx)
	{
		ft_printf("probleme");
		exit(EXIT_FAILURE);
	}
	game = read_map(map_file);
	game->height = count_line(map_file);
	game->width = ft_strlen_so(game->grid[0]) - 1;
	return (game);
}

void load_textures(t_map *game)
{
	mlx_texture_t *texture;
	texture = mlx_load_png("./includes/images/wall.png");
	game->wall = mlx_texture_to_image(game->mlx, texture);
	texture = mlx_load_png("./includes/images/floor.png");
	game->floor = mlx_texture_to_image(game->mlx, texture);
	texture = mlx_load_png("./includes/images/player.png");
	game->player = mlx_texture_to_image(game->mlx, texture);
	texture = mlx_load_png("./includes/images/collectible.png");
	game->collectible = mlx_texture_to_image(game->mlx, texture);
	texture = mlx_load_png("./includes/images/exit.png");
	game->exit = mlx_texture_to_image(game->mlx, texture);
	if (!texture)
		mlx_delete_texture(texture);
}
