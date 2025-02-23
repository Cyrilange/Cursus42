#include "../includes/so_long.h"

static void delete_textures(t_game *game)
{
    if (game->img.floor.t)
    {
        mlx_delete_texture(game->img.floor.t);
        game->img.floor.t = NULL;
    }
    if (game->img.wall.t)
    {
        mlx_delete_texture(game->img.wall.t);
        game->img.wall.t = NULL;
    }
    if (game->img.player.t)
    {
        mlx_delete_texture(game->img.player.t);
        game->img.player.t = NULL;
    }
    if (game->img.collectable.t)
    {
        mlx_delete_texture(game->img.collectable.t);
        game->img.collectable.t = NULL;
    }
    if (game->img.exit.t)
    {
        mlx_delete_texture(game->img.exit.t);
        game->img.exit.t = NULL;
    }
}

void terminate_game(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->file.map_height)
		free(game->file.map[i]);
	free(game->file.map);
	if (game->img.wall.i)
	{
		delete_textures(game);
		mlx_terminate(game->mlx);
	}
}
