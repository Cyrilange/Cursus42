#include "../includes/so_long.h"

void cleanup(t_data *data) {
    if (!data) return; // Safeguard against NULL data

    if (data->wall)
        mlx_delete_image(data->mlx, data->wall); // Use mlx_delete_image
    if (data->empty)
        mlx_delete_image(data->mlx, data->empty);
    if (data->object)
        mlx_delete_image(data->mlx, data->object);
    if (data->player)
        mlx_delete_image(data->mlx, data->player);
    if (data->exit)
        mlx_delete_image(data->mlx, data->exit);

    if (data->mlx) {
        mlx_terminate(data->mlx); // Use mlx_terminate to free all mlx resources
    }

    ft_free_map(data->map); // Assuming ft_free_map is defined elsewhere and frees the map data
    free(data); // Free the data structure itself (if it was dynamically allocated)
}

char	**ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (NULL);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

void	ft_check_fd(int fd)
{
	if (fd < 0)
	{
		ft_printf("Error\nFailed to read file (fd error)\n");
		exit(0);
	}
}

void	ft_error_map_init(void)
{
	ft_printf("Error\nMap ends with an empty line\n");
	exit(0);
}