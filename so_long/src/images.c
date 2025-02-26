#include "../includes/so_long.h"

size_t	lign_map(char *file_lign)
{
	int	i;

	i = 0;
	while (file_lign[i])
		i++;
	if (file_lign[i - 1] == '\n')
		i--;
	return (i);
}

static void	load_texture(t_game *game)
{
	game->img.floor.i = mlx_texture_to_image(game->mlx, game->img.floor.t);
	game->img.wall.i = mlx_texture_to_image(game->mlx, game->img.wall.t);
	game->img.player.i = mlx_texture_to_image(game->mlx, game->img.player.t);
	game->img.collectable.i = mlx_texture_to_image(game->mlx, 
			game->img.collectable.t);
	game->img.exit.i = mlx_texture_to_image(game->mlx, game->img.exit.t);
}

void	load_images(t_game *game)
{
	game->img.floor.t = mlx_load_png("./includes/images/floor.png");
	game->img.wall.t = mlx_load_png("./includes/images/wall.png");
	game->img.player.t = mlx_load_png("./includes/images/player.png");
	game->img.collectable.t = mlx_load_png("./includes/images/collective.png");
	game->img.exit.t = mlx_load_png("./includes/images/exit.png");
	if (!game->img.floor.t || !game->img.wall.t || !game->img.player.t 
		|| !game->img.collectable.t || !game->img.exit.t)
		return ;
	load_texture(game);
}
