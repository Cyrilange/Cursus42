#include "../includes/so_long.h"


static void fill(char **tab, t_map size, int x, int y, char player) {
	if (x >= 0 && x < size.x && y >= 0 && y < size.y && tab[y][x] == player) {
		tab[y][x] = 'P';
		fill(tab, size, x + 1, y, player);
		fill(tab, size, x - 1, y, player);
		fill(tab, size, x, y + 1, player);
		fill(tab, size, x, y - 1, player);
	}
}

void flood_fill(char **tab, t_map size, t_map begin)
{
	char	player;
    
    player = tab[begin.y][begin.x];
	if (player != 1)
		fill(tab, size, begin.x, begin.y, player);
}

/*int	check_exit(t_map *col, char target)
{
	if (target == 'E' && col->collectible == 0)
	{
		printf("You made it, congrats");
		ft_free(col);
	}
	if (target == 'E' && col->collectible != 0)
	{
		printf("You need to put some gas first!!!!!");
		return (1);
	}
	return (0);
}*/
