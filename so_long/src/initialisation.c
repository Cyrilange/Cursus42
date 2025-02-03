#include "../includes/so_long.h"

char *get_map_path(const char *map_name)
{
    const char *map_dir = "./includes/maps/";
    if (strncmp(map_name, map_dir, strlen(map_dir)) == 0)
        return strdup(map_name);
    char *map_path = malloc(strlen(map_dir) + strlen(map_name) + 1);
    if (!map_path) {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(map_path, map_dir);
    strcat(map_path, map_name);

    printf("route: %s\n", map_path);

    return map_path;
}


void init_game(t_map *game, const char *map_name)
{
    int width, height;
    char *map_file = get_map_path(map_name);

    game->map = load_map(map_file, &width, &height);
    if (!game->map)
    {
        printf("Error: Failed to load map\n");
        exit(EXIT_FAILURE);
    }
    game->width = width;
    game->height = height;
    init_images(game);
}

void find_player_position(t_map *game)
{
    for (int y = 0; y < game->height; y++)
    {
        for (int x = 0; x < game->width; x++)
        {
            if (game->map[y][x] == 'P')
            {
                game->player_pos.x = x;
                game->player_pos.y = y;
                return;
            }
        }
    }
}