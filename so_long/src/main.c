#include "../includes/so_long.h"

static int ft_check_map_extension(char *filename)
{
    int len = ft_strlen(filename);
    
    if (len < 4)
        return (0);
    return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

static void ft_initialisation(t_data *game)
{
    game->count_move = 0;
    game->count_star = 0;
    game->total_star = ft_count_char(game->map, 'C');
    game->exit_position = ft_locate(game->map, 'E');
}

int main(int argc, char **argv)
{
    t_data	game;

    if (argc != 2 || !ft_check_map_extension(argv[1]))
    {
        ft_printf("Error\nMap file is false or missing.\n");
        return (1);
    }
    if (!ft_check_map(&game, argv[1]))
    {
        ft_printf("Error\nInvalid map.\n");
        return (1);
    }
    ft_initialisation(&game);
    load_images(&game);
    render_map(&game);

    mlx_key_hook(game.mlx, key_press, &game);
    mlx_loop(game.mlx);

    exit_map(&game);
    return (0);
}
