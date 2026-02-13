/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-28 13:33:11 by csalamit          #+#    #+#             */
/*   Updated: 2024-04-28 13:33:11 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *src, size_t n)
{
	char	*dup;
	size_t	i;

	dup = malloc(n + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static int	num_words(const char *s, char c)
{
	int	num;

	num = 0;
	while (*s)
	{
		if (*s != c)
		{
			num++;
			while (*s && *s != c)
				s++;
			if (!*s)
				break ;
		}
		s++;
	}
	return (num);
}

static char	*get_next_word(const char **s, char c)
{
	const char	*start;
	const char	*end;

	start = *s;
	while (*start && *start == c)
		start++;
	end = start;
	while (*end && *end != c)
		end++;
	if (start == end)
		return (NULL);
	*s = end;
	return (ft_strndup(start, end - start));
}

char	**ft_split(char const *s, char c)
{
	int		word_num;
	char	**res;
	int		i;

	if (!s)
		return (NULL);
	word_num = num_words(s, c);
	res = malloc((word_num + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			res[i] = get_next_word(&s, c);
			if (!res[i])
				break ;
			i++;
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}
