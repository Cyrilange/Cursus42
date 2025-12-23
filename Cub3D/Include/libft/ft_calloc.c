/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-20 15:12:08 by csalamit          #+#    #+#             */
/*   Updated: 2024-04-20 15:12:08 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	len;
	void	*mem;

	len = count * size;
	mem = malloc(len);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, len);
	return (mem);
}
