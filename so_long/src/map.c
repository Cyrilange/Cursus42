#include "../includes/so_long.h"

#define TILE_SIZE 40
#define MAX_WIDTH  1600 / TILE_SIZE
#define MAX_HEIGHT 900 / TILE_SIZE

int count_line(const char *file)
{
    int fd, count;
    char buffer;
    ssize_t bytes_read;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (-1);

    count = 0;
    while ((bytes_read = read(fd, &buffer, 1)) > 0)
    {
        if (buffer == '\n')
            count++;
    }
    close(fd);
    if (bytes_read < 0)
        return -1;
    else
        return count + 1;
}

t_map *create_map(void)
{
    t_map *map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->width = 10;
    map->height = 5;
    return (map);
}

t_map *read_map(const char *file) {
    int fd, i;
    char *line;
    t_map *map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);

    map->height = count_line(file); // Initial estimate
    if (map->height > MAX_HEIGHT) {
        free(map);
        return NULL;
    }

    map->grid = malloc(sizeof(char *) * (map->height + 1));
    if (!map->grid) {
        free(map);
        return NULL;
    }

    fd = open(file, O_RDONLY);
    if (fd < 0) {
        free(map->grid);
        free(map);
        return NULL;
    }

    i = 0;
    while ((line = get_next_line(fd)) != NULL) {
        if (ft_strlen_so(line) == 0) {
            free(line);
            continue;
        }

        if (i == 0) {
            printf("First line: [%s]\n", line);
            map->width = ft_strlen_so(line); // Calculate width AFTER reading the line
            if (map->width == 0) { // Handle empty first line
                free(line);
                free_map(map);
                close(fd);
                return NULL; // Map is invalid
            }
        }

        if (map->width > MAX_WIDTH) {
            free_map(map);
            close(fd);
            return NULL;
        }

        map->grid[i++] = line; // Assign line, THEN increment i
        ft_printf(" Nombre de lignes détectées : %d\n", map->height);
    }

    map->grid[i] = NULL; // Correct: Assign NULL AFTER the loop

    map->height = i; // **KEY CHANGE: Update map->height with the actual count**

    close(fd);
    ft_printf("\n Carte lue :\n");
    for (int j = 0; j < map->height; j++) // Use updated map->height
        ft_printf("Ligne %d : [%s]\n", j, map->grid[j]);
    for (int y = 0; y < map->height; y++) {
        printf("Length of row %d: %d\n", y, ft_strlen_so(map->grid[y]));
}
    return (map);
}

void free_map(t_map *map) {
    if (!map || !map->grid) return; // Check map and grid

    for (int i = 0; i < map->height; i++) { // Use map->height
        if (map->grid[i] != NULL) { // Check if row was allocated
            free(map->grid[i]);
        }
    }
    free(map->grid);
    free(map);
}

int validate_map(t_map *map)
{
    int i = 1;
    if (!map || !map->grid)
        return (0);
    
    while (i < map->width)
    {
        if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
            return (0);
        i++;
    }
    i = 1;
    while (i < map->height - 1)
    {
        if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

void display_map(t_game *game)
{
    int y = 0;
    if (game->mlx == NULL) {
        ft_printf("ERROR: game->mlx is NULL!\n");
        return;
    }
    while (y < game->map->height)
    {
        int x = 0;
        int row_width = ft_strlen_so(game->map->grid[y]);

        while (x < row_width)
        {
            char tile = game->map->grid[y][x];
            ft_printf("️ (%d, %d) = %c\n", y, x, tile);

            mlx_image_t *img = NULL; // Initialize to NULL

            if (tile == '1')
            {
                img = game->wall;
            }
            else if (tile == '0')
            {
                img = game->floor;
            }
            else if (tile == 'P')
            {
                img = game->player;
            }
            else if (tile == 'C')
            {
                img = game->collectible;
            }
            else if (tile == 'E')
            {
                img = game->exit;
            }

            if (img != NULL) // Check if img is not NULL
            {
                mlx_image_to_window(game->mlx, img, x * TILE_SIZE, y * TILE_SIZE);
            }

            x++;
        }
        y++;
    }
}

mlx_image_t *load_and_convert_texture(t_game *game, const char *file_path)
{
    mlx_texture_t *texture = mlx_load_png(file_path);
    if (!texture) {
        ft_printf("Erreur: Impossible de charger %s\n", file_path); // Print the path!
        exit(EXIT_FAILURE);
        return NULL; // Still return NULL after exiting
    }

    mlx_image_t *image = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);
    if (!image) {
        ft_printf("Erreur: Impossible de convertir %s en image\n", file_path); // Print the path!
        exit(EXIT_FAILURE);
        return NULL; // Still return NULL after exiting
    }

    return (image);
}

void load_textures(t_game *game)
{
    if (!game || !game->mlx)
    {
        ft_printf("Erreur: MLX non initialisé.\n");
        exit(EXIT_FAILURE);
    }

    game->wall = load_and_convert_texture(game, "/home/csalamithome/Cursus42/so_long/includes/images/wall.png");
    ft_printf("✅ wall chargée\n");
    
    game->floor = load_and_convert_texture(game, "/home/csalamithome/Cursus42/so_long/includes/images/floor.png");
    ft_printf("✅ floor chargée\n");
    
    game->player = load_and_convert_texture(game, "/home/csalamithome/Cursus42/so_long/includes/images/player.png");
    ft_printf("✅ player chargé\n");
    
    game->collectible = load_and_convert_texture(game, "/home/csalamithome/Cursus42/so_long/includes/images/collective.png");
    ft_printf("✅ collectible chargé\n");
    
    game->exit = load_and_convert_texture(game, "/home/csalamithome/Cursus42/so_long/includes/images/exit.png");
    ft_printf("✅ exit chargé\n");
}

