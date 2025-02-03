/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-13 13:42:04 by csalamit          #+#    #+#             */
/*   Updated: 2024-04-13 13:42:04 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*receiver;

	receiver = dst;
	if (!dst && !src)
	{
		return ((char *) dst);
	}
	while (n--)
	{
		*(char *)dst++ = *(char *)src++;
	}
	return (receiver);
}
