#include "../includes/so_long.h"

t_game  int_game_function(t_game *game)
{
    game->mlx = NULL;
    game->map = NULL;
    game->path = NULL;
    game->grid_b = 0;
    game->grid_y = NULL;
    game->player.x = 0;
    game->player.y = 0;
    game->size_pix.x = 0;
    game->size_pix.y = 0;
    game->mouv = 0;
    game->collect_taken = 0;
}

void	init_game_object(t_grid *obj)
{
	obj->player = 0;
	obj->collectible = 0;
	obj->exit = 0;
}

void	init_textures(t_game *game)
{
	game->textures.wall = mlx_load_png("./includes/images/wall.png");
	game->textures.player = mlx_load_png("./includes/images/player.png");
	game->textures.floor = mlx_load_png("./includes/images/floor.png");
	game->textures.collectible = mlx_load_png("./includes/images/collective.png");
	game->textures.exit = mlx_load_png("./includes/images/exit.png");
	if (!game->textures.wall || !game->textures.floor || !game->textures.player
		|| !game->textures.exit || !game->textures.collectible)
	{
		ft_printf("The textures could not be loaded..\n");
		ft_free_all(game, 1);
		exit(FAIL);
	}
}

void	init_images(t_game *game)
{
	game->images.wall_img = mlx_texture_to_image(game->mlx, game->textures.wall);
    game->images.player_img = mlx_texture_to_image(game->mlx, game->textures.player);
    game->images.floor_img = mlx_texture_to_image(game->mlx, game->textures.floor);
    game->images.exit_img = mlx_texture_to_image(game->mlx, game->textures.exit);
    game->images.collectible_img = mlx_texture_to_image(game->mlx, game->textures.collectible);
}