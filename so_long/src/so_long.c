#include "../includes/so_long.h"

int main(int argc, char **argv)
{
    t_map game;

    if (argc != 2)
    {
        printf("Usage: ./so_long <map_file.ber>\n");
        return (1);
    }
	
    init_game(&game, argv[1]);
    game.mlx = mlx_init(WIDTH, HEIGHT, "So Long", true);
    if (!game.mlx)
    {
        printf("Error: Failed to initialize MLX\n");
        return (1);
    }

    render_game(&game);
    mlx_loop(game.mlx);
	free_all(&game, 1);
    return (0);
}
