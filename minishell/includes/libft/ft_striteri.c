/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-04 10:07:52 by csalamit          #+#    #+#             */
/*   Updated: 2024-05-04 10:07:52 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	nbr;

	nbr = 0;
	if (s == NULL || f == NULL)
		return ;
	while (*s)
	{
		f(nbr++, s++);
	}
}
