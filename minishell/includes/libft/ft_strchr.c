/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-14 11:46:46 by csalamit          #+#    #+#             */
/*   Updated: 2024-04-14 11:46:46 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			j;

	j = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == j)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == j)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
