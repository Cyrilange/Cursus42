/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_lowercase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-28 09:04:33 by csalamit          #+#    #+#             */
/*   Updated: 2024-05-28 09:04:33 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_lowercase(unsigned long long num)
{
	int		numero;
	char	*hex;

	numero = 0;
	hex = "0123456789abcdef";
	if (num >= 16)
	{
		numero += ft_hex_lowercase(num / 16);
		ft_putchar(hex[num % 16]);
		numero++;
	}
	else
	{
		ft_putchar(hex[num]);
		numero++;
	}
	return (numero);
}
