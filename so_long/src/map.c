#include "../includes/so_long.h"

static inline int get_x_pos(int x, t_map *game) { return (x * WIDTH / game->width); }
static inline int get_y_pos(int y, t_map *game) { return (y * HEIGHT / game->height); }


void	read_map(t_map *game, char *file)
{
	int		fd;
	char	*line;
	char	*holder;
	char	*all_lines;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	if (line)
		game->width = ft_strlen(line) - 1;
	all_lines = ft_strdup("");
	while (line)
	{
		game->height++;
		holder = all_lines;
		all_lines = ft_strjoin(holder, line);
		free(line);
		free(holder);
		line = get_next_line(fd);
	}
	game->map = ft_split(all_lines, '\n');
	free(line);
	close(fd);
}

void    init_images(t_map *game)
{
    mlx_texture_t *texture;

    texture = mlx_load_png("./includes/images/player.png");
    if (!texture)
        return;
    game->player = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    texture = mlx_load_png("./includes/images/floor.png");
    if (!texture)
        return ;
    game->floor = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    texture = mlx_load_png("./includes/images/wall.png");
    if (!texture)
        return;
    game->wall = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    texture = mlx_load_png("./includes/images/collective.png");
    if (!texture)
        return ;
    game->collectible = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    texture = mlx_load_png("./includes/images/exit.png");
    if (!texture)
        return ;
    game->exit = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    if (!game->player || !game->floor || !game->wall || !game->collectible || !game->exit)
    {
        ft_printf("Issue with graphics textures\n");
        free_all(game, 1);
        exit(EXIT_FAILURE);
    }
}

void    render_game(t_map *game)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while (y < game->height)
    {
        while (x < game->width)
        {
            if (game->map[y][x] == '1')
                mlx_image_to_window(game->mlx, game->wall, get_x_pos(x, game), get_y_pos(y, game));
            else if (game->map[y][x] == '0')
                mlx_image_to_window(game->mlx, game->floor, get_x_pos(x, game), get_y_pos(y, game));
            else if (game->map[y][x] == 'P')
                mlx_image_to_window(game->mlx, game->player, get_x_pos(x, game), get_y_pos(y, game));
            else if (game->map[y][x] == 'C')
                mlx_image_to_window(game->mlx, game->collectible, get_x_pos(x, game), get_y_pos(y, game));
            else if (game->map[y][x] == 'E')
                mlx_image_to_window(game->mlx, game->exit, get_x_pos(x, game), get_y_pos(y, game));
            x++;
        }
        y++;
    }
}