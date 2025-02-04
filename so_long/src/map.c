#include "../includes/so_long.h"

int count_line(const char *file)
{
	int		fd;
	int		count;
	char	buffer;

	fd = open(file, O_RDONLY);
	count = 0;
	if (fd < 0)
		return (-1);
	while (read(fd, &buffer, 1))
		if (buffer == '\n')
			count++;
	close(fd);
	return (count + 1);
}

t_map *create_map(void)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = 10;
	map->height = 5;
	return (map);
}
t_map *read_map(const char *file)
{
    int fd;
    int i;
    char *line;
    t_map *map;

    map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->height = count_line(file);
    map->grid = malloc(sizeof(char *) * (map->height + 1));
    if (!map->grid)
    {
        free(map);
        exit(EXIT_FAILURE);
    }
    fd = open(file, O_RDONLY);
    if (fd < 0) // Vérifie que le fichier s'ouvre bien
    {
        free(map->grid);
        free(map);
        return (NULL);
    }
    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        map->grid[i++] = line;
    }
    map->grid[i] = NULL;

    if (i > 0)
        map->width = strlen(map->grid[0]) - 1;
    else
        map->width = 0;

    close(fd);
    return (map);
}

void free_map(t_map *map)
{
    int i = 0;
    while (map->grid[i])
        free(map->grid[i++]);
    free(map->grid);
    free(map);
}

int validate_map(t_map *map)
{
	int	i;
	
	i = 0;
    while (i < map->width)
    {
        if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
            return 0;
		i++;
    }
    while (i < map->height - 1)
    {
        if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
            return 0;
		i++;
    }

    return 1;
}

void display_map(t_map *game)
{
    int     y;
    int     x;
    char    tile;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            tile = game->grid[y][x];

            if (tile == '1')
                mlx_image_to_window(game->mlx, game->wall, x * WIDHT, y * HEIGHT);
            else if (tile == '0')  // Sol
                mlx_image_to_window(game->mlx, game->floor, x * WIDHT, y * HEIGHT);
            else if (tile == 'P')  // Joueur
                mlx_image_to_window(game->mlx, game->player, x * WIDHT, y * HEIGHT);
            else if (tile == 'C')  // Collectible
                mlx_image_to_window(game->mlx, game->collectible, x * WIDHT, y * HEIGHT);
            else if (tile == 'E')  // Sortie
                mlx_image_to_window(game->mlx, game->exit, x * WIDHT, y * HEIGHT);
            x++;
        }
        y++;
    }
    
    
    
}
