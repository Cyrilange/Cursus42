/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-13 13:58:43 by csalamit          #+#    #+#             */
/*   Updated: 2024-04-13 13:58:43 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*j;
	size_t			i;

	i = 0;
	j = b;
	while (i < len)
	{
		j[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
