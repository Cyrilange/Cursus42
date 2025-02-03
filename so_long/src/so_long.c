#include "../includes/so_long.h"

int main(int argc, char **argv)
{
    t_map game;
    
    if (argc != 2)
    {
        ft_printf("Usage: ./so_long <map_file>\n");
        return (EXIT_FAILURE);
    }

    // Initialize the game with the map file
    init_struct(&game, argv[1]);
    
    // Perform flood fill to mark the accessible area from the player's start position
    perform_flood_fill(&game);

    // Render the game (you might want to put it in the game loop if needed)
    render_game(&game);

    // Set up key event handling
    mlx_key_hook(game.mlx, key_press, &game);
    
    // Run the MLX42 loop to handle events
    mlx_loop(game.mlx);

    return (EXIT_SUCCESS);
}

