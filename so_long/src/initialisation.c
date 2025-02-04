#include "../includes/so_long.h"

t_map *init_game(const char *map_file)
{
	t_map *game;
    
	game = malloc(sizeof(t_map));
	if (!game)
		exit(EXIT_FAILURE);
	game->mlx = mlx_init(WIDHT * 15, HEIGHT * 10, "so_long", false);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game = read_map(map_file);
	game->height = count_line(map_file);
	game->width = ft_strlen2(game->grid[0]) - 1;
	return (game);
}

void load_textures(t_map *game)
{
	mlx_texture_t *texture;
	texture = mlx_load_png("./includes/images/wall.png");
	game->wall = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./includes/images/floor.png");
	game->floor = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./includes/images/player.png");
	game->player = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./includes/images/collectible.png");
	game->collectible = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./includes/images/exit.png");
	game->exit = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}
