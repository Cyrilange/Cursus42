#include "../includes/so_long.h"

static t_game	**ft_check_flood(t_game	**game, char check)
{
	if (check == 'C')
	{
		(*game)->grid.collectible++;
		(*game)->collect_taken++;
	}
	if (check == 'P')
		(*game)->grid.player++;
	if (check == 'E')
		(*game)->grid.exit++;
	return (game);
}

static t_game  **ft_flood_fill(char **tab, t_coord  size_pix, t_coord current_pos, t_game   **game)
{
    if (current_pos.x < 0 || current_pos.x >= size_pix.x || current_pos.y < 0 || current_pos.y >= size_pix.y
            || tab[current_pos.y][current_pos.x] == '1' || tab[current_pos.y][current_pos.x] == 'F')
                return (game);
    game = ft_check_flood(game, tab[current_pos.y][current_pos.x]);
    tab[current_pos.y][current_pos.x] = 'F';
    ft_flood_fill(tab, size_pix, (t_coord){current_pos.x - 1, current_pos.y}, game);
    ft_flood_fill(tab, size_pix, (t_coord){current_pos.x + 1, current_pos.y}, game);
    ft_flood_fill(tab, size_pix, (t_coord){current_pos.x, current_pos.y - 1}, game);
    ft_flood_fill(tab, size_pix, (t_coord){current_pos.x, current_pos.y + 1}, game);
    return (game);
}

t_game *init_flood_fill(t_game *game)
{
    game->grid.player = 0;
    game->grid.collectible = 0;
    game->grid.exit = 0;
    game = ft_flood_fill(game->grid_b, game->size_pix, game->player, &game);
    return (game);
}