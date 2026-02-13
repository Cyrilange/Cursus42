/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-01 18:10:48 by csalamit          #+#    #+#             */
/*   Updated: 2024-09-01 18:10:48 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	ft_strlen_get(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((ft_strlen_get(s1)
				+ ft_strlen_get(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (s1[i])
		join[j++] = s1[i++];
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	join[j] = '\0';
	return (join);
}

char	*ft_joinfree(char *buffer, char *aux)
{
	char	*temp;

	temp = ft_strjoin(buffer, aux);
	if (!temp)
		return (ft_free(buffer));
	else if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	return (temp);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

void	*ft_gnl_calloc(size_t count, size_t size)
{
	char		*result;
	size_t		i;

	i = 0;
	result = malloc(count * size);
	if (result != NULL)
	{
		while (i < size * count)
		{
			result[i] = 0;
			i++;
		}
	}
	return ((void *)result);
}
