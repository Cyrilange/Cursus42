#include "../includes/so_long.h"

int main(int argc, char **argv)
{
    t_map game;

    if (argc != 2)  // Vérifie qu'on a bien un argument (le fichier .ber)
    {
        printf("Usage: ./so_long <map_file.ber>\n");
        return (1);
    }
	
    init_game(&game, argv[1]);  // On passe le fichier en paramètre
    game.mlx = mlx_init(WIDTH, HEIGHT, "So Long", true);
    if (!game.mlx)
    {
        printf("Error: Failed to initialize MLX\n");
        return (1);
    }

    render_game(&game);
    mlx_loop(game.mlx);
    return (0);
}
