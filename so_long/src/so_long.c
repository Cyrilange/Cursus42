#include "../includes/so_long.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: ./so_long <map_file>\n");
        return (1);
    }

    t_map *game = init_game(argv[1]);

    mlx_loop(game->mlx);
	free_game(game);

    return (0);
}
