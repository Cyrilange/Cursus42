/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:14:16 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/31 16:44:48 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line/get_next_line_bonus.h"

static void	add_line(t_line **head, char *line)
{
	t_line	*new;
	t_line	*tmp;
	char	*trimmed;

	trimmed = ft_strtrim(line, " \t\n\r");
	if (!trimmed || !*trimmed)
	{
		free(trimmed);
		return ;
	}
	new = check_malloc(sizeof(t_line));
	new->content = ft_strdup(trimmed);
	new->next = NULL;
	free(trimmed);
	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static void	assign_texture_path(t_game *game,
	char **dest, const char *line, int offset)
{
	char	*path;
	char	*trimmed;

	if (*dest != NULL)
	{
		free((void *)line);
		g_error_function(game, "Error\n duplicate texture path");
	}
	trimmed = ft_strtrim(line + offset, " \t\n\r");
	if (!trimmed || !*trimmed)
	{
		free(trimmed);
		g_error_function(game, "Error\n invalid or empty texture path");
	}
	path = ft_strdup(trimmed);
	free(trimmed);
	if (!path)
		g_error_function(game,
			"Error\n malloc failed when copying texture path");
	*dest = path;
}

int	handle_line(t_game *game, char *line, t_line **lines)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		assign_texture_path(game, &game->texture.no_path, line, 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		assign_texture_path(game, &game->texture.so_path, line, 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		assign_texture_path(game, &game->texture.ea_path, line, 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		assign_texture_path(game, &game->texture.we_path, line, 3);
	else if (line[0] == 'F')
		game->texture.floor = parse_color(line + 2);
	else if (line[0] == 'C')
		game->texture.ceilling = parse_color(line + 2);
	else if (ft_strchr("01NSEW", line[0]))
		add_line(lines, line);
	return (0);
}

static void	convert_list_to_map(t_map *map, t_line *list)
{
	t_line	*tmp;
	int		i;

	tmp = list;
	map->map_height = 0;
	map->map_width = 0;
	while (tmp)
	{
		map->map_height++;
		if ((int)ft_strlen(tmp->content) > map->map_width)
			map->map_width = ft_strlen(tmp->content);
		tmp = tmp->next;
	}
	map->map = check_malloc(sizeof(char *) * (map->map_height + 1));
	i = 0;
	while (list)
	{
		map->map[i++] = list->content;
		tmp = list->next;
		free(list);
		list = tmp;
	}
	map->map[i] = NULL;
}

void	parse_map_file(const char *filename, t_game *game)
{
	int		fd;
	char	*line;
	t_line	*lines;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_function("Error\n cannot open map file");
	lines = NULL;
	line = get_next_line(fd);
	while (line)
	{
		handle_line_or_exit(game, line, &lines);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	convert_list_to_map(&game->map, lines);
}
