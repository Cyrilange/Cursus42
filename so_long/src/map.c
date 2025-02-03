#include "../includes/so_long.h"

static inline int get_x_pos(int x, t_map *game) { return (x * WIDTH / game->width); }
static inline int get_y_pos(int y, t_map *game) { return (y * HEIGHT / game->height); }



char **load_map(char *file, int *width, int *height)
{
    int fd = open(file, O_RDONLY);
    char *line;
    char **map;
    int i;

    i = 0;
    *height = 0;
    *width = 0;
    file = get_map_path(file);
    printf("Generated path: %s\n", file);

    if (fd < 0)
    {
        return (NULL);
        perror("Error opening file");
    }
    while ((line = get_next_line(fd)))
    {
        printf("Reading line: %s", line);
        if (*width == 0)
            *width = ft_strlen(line) - 1;
        (*height)++;
        free(line);
    }
    close(fd);
    fd = open(file, O_RDONLY);
    map = malloc(sizeof(char *) * (*height + 1));
    if (!map)
    {
        ft_printf("Error: Memory allocation for map failed\n");
        return NULL;
    }
    while (i++ < *height)
        map[i] = get_next_line(fd);
    map[*height] = NULL;
    close(fd);
    return (map);
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