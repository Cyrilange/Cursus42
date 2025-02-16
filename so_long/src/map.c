#include "../includes/so_long.h"

size_t	ft_count_line(char **argv)
{
	int		fd;
	size_t	count;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	ft_check_fd(fd);
	count = 0;
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error\nFile is empty\n");
		exit(0);
	}
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static void	ft_check_endl(char **argv)
{
	int		fd;
	char	*line;
	int		i;
	size_t	count_endl;

	count_endl = 0;
	fd = open(argv[1], O_RDONLY);
	ft_check_fd(fd);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == '\n')
				count_endl++;
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
	if (count_endl == ft_count_line(argv))
		ft_error_map_init();
}

static char	*ft_map_extension(int j, char *line, char **map)
{
	int	i;

	i = 0;
	map[j] = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!map[j])
	{
		while (j-- > 0)
			free(map[j]);
		free(map);
		return (NULL);
	}
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		map[j][i] = line[i];
		i++;
	}
	map[j][i] = '\0';
	free(line);
	return (map[j]);
}

char	**ft_map(char **argv)
{
	char	**map;
	int		j;
	int		line_count;
	int		fd;
	char	*line;

	ft_check_endl(argv);
	fd = open(argv[1], O_RDONLY);
	ft_check_fd(fd);
	j = 0;
	line_count = ft_count_line(argv);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	while (j < line_count || get_next_line(fd))
	{
		line = get_next_line(fd);
		map[j] = ft_map_extension(j, line, map);
		if (!map[j])
			return (NULL);
		j++;
	}
	map[j] = NULL;
	close(fd);
	return (ft_check_map(map, argv));
}