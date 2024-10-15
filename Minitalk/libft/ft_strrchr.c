/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-20 09:02:43 by csalamit          #+#    #+#             */
/*   Updated: 2024-04-20 09:02:43 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*result;
	char			j;

	j = (char) c;
	result = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == j)
		{
			result = ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == j)
	{
		result = ((char *) &s[i]);
	}
	return (result);
}
