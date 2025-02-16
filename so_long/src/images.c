#include "../includes/so_long.h"

void exit_map(t_data *game)
{
    mlx_close_window(game->mlx);  // Ferme la fenêtre MLX42
    cleanup(game);                // Libère la mémoire et les ressources
    exit(0);                      // Quitte proprement le programme
}

void render_tile(t_data *game, int x, int y, char tile)
{
    mlx_image_t *img = NULL;

    if (tile == '1')
        img = game->wall;
    else if (tile == '0')
        img = game->empty;
    else if (tile == 'P')
        img = game->player;
    else if (tile == 'C')
        img = game->object;
    else if (tile == 'E')
        img = game->exit;
    if (img)
        mlx_image_to_window(game->mlx, img, x * TS, y * TS);
}

void load_images(t_data *game)
{
    mlx_texture_t *texture;

    texture = mlx_load_png("./includes/images/wall.png");
    game->wall = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    texture = mlx_load_png("./includes/images/floor.png");
    game->empty = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    texture = mlx_load_png("./includes/images/collective.png");
    game->object = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    texture = mlx_load_png("./includes/images/player.png");
    game->player = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    texture = mlx_load_png("./includes/images/exit.png");
    game->exit = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    if (!game->wall || !game->empty || !game->object || !game->player || !game->exit)
    {
        ft_printf("Error\nFailed to load images\n");
        exit_map(game);
        exit(1);
    }
}

void render_map(t_data *game)
{
    int y = 0;
    int x;

    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            render_tile(game, x, y, game->map[y][x]);
            x++;
        }
        y++;
    }
}
