#include "../includes/so_long.h"

static int add_to_map(t_game *game, char *line)
{
    char	**temp;
	int		i;

	if (!line)
		return (1);
	i = 0;
	game->file.map_height++;
	temp = ft_calloc(game->file.map_height + 1, sizeof(char *));
	temp[game->file.map_height] = NULL;
	while (i < game->file.map_height - 1)
	{
		temp[i] = game->file.map[i];
		i++;
	}
	if (game->file.map)
		free(game->file.map);
	temp[i] = line;
	game->file.map = temp;
	return (0);
}

int	read_map(t_game *game, char *file)
{
	char	*temp_line;

	if (!ft_strnstr(file, ".ber", ft_strlen(file)))
		return (1);
	game->file.fd = open(file, O_RDONLY);
	if (game->file.fd < 0)
		return (1);
	while (true)
	{
		temp_line = get_next_line(game->file.fd);
		if (add_to_map(game, temp_line))
			break ;
	}
	close(game->file.fd);
	game->file.map_width = lign_map(game->file.map[0]);
	return (0);
}


void	update_map(t_game *game, int next_y, int next_x)
{
	game->file.map[game->dir.y][game->dir.x] = '0';
	game->file.map[next_y][next_x] = 'P';
	image_towindow_size(game, &game->img.player, next_x, next_y);
	image_towindow_size(game, &game->img.floor, game->dir.x, game->dir.y);
}
