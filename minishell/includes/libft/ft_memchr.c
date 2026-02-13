/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-21 14:08:20 by csalamit          #+#    #+#             */
/*   Updated: 2024-04-21 14:08:20 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	let;
	size_t	num;

	str = (char *)s;
	let = (char)c;
	num = 0;
	while (num < n)
	{
		if (str[num] == let)
			return ((void *)(str + num));
		num++;
	}
	return (0);
}
