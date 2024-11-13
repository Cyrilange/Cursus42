/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-28 09:05:14 by csalamit          #+#    #+#             */
/*   Updated: 2024-05-28 09:05:14 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_nbr(unsigned int n)
{
	int				len;
	const char		*base;
	size_t			base_len;
	unsigned long	remainder;
	char			c;

	len = 0;
	base = "0123456789";
	base_len = ft_strlen(base);
	if (n >= base_len)
		len += ft_unsigned_nbr(n / base_len);
	remainder = n % base_len;
	c = base[remainder];
	len = len + ft_putchar(c);
	return (len);
}
