/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 08:59:24 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/29 11:54:34 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *buffer)
{
	free(buffer);
	buffer = NULL;
	return (NULL);
}

char	*ft_read_line(char *buffer)
{
	char	*left;
	ssize_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	left = (char *)ft_gnl_calloc(i + 1 + (buffer[i] == '\n'), 1);
	if (!left)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		left[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		left[i] = '\n';
	return (left);
}

char	*ft_fill_line(char *buffer, int fd)
{
	ssize_t	reed;
	char	*temp;

	if (!buffer)
	{
		buffer = ft_gnl_calloc(1, 1);
		if (!buffer)
			return (NULL);
	}
	temp = ft_gnl_calloc(BUFFER_SIZE + 1, 1);
	if (!temp)
		return (ft_free(buffer));
	reed = 1;
	while ((!ft_strchr(temp, '\n')) && reed > 0)
	{
		reed = read(fd, temp, BUFFER_SIZE);
		if (reed == -1)
			return (ft_free(buffer));
		temp[reed] = '\0';
		buffer = ft_joinfree(buffer, temp);
		if (!buffer)
			return (NULL);
	}
	free(temp);
	return (buffer);
}

char	*ft_update(char *buffer)
{
	int		i;
	int		j;
	char	*upt;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (ft_free(buffer));
	upt = ft_gnl_calloc((ft_strlen_get(buffer) - i + 1), sizeof(char));
	if (!upt)
		return (ft_free(buffer));
	i++;
	j = 0;
	while (buffer[i])
		upt[j++] = buffer[i++];
	free(buffer);
	return (upt);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;
	int			i;

	i = -1;
	if (fd == -1)
	{
		while (++i < OPEN_MAX)
		{
			if (buffer[i])
			{
				free(buffer[i]);
				buffer[i] = NULL;
			}
		}
		return (NULL);
	}
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_fill_line(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	line = ft_read_line(buffer[fd]);
	buffer[fd] = ft_update(buffer[fd]);
	return (line);
}
