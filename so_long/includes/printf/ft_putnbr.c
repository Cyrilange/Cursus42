/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-28 09:05:00 by csalamit          #+#    #+#             */
/*   Updated: 2024-05-28 09:05:00 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long	i;
	int		numero;

	i = nb;
	numero = 0;
	if (i < 0)
	{
		ft_putchar('-');
		numero++;
		i = -i;
	}
	if (i >= 10)
	{
		numero += ft_putnbr(i / 10);
		i = i % 10;
	}
	if (i < 10)
	{
		ft_putchar(i + 48);
		numero++;
	}
	return (numero);
}
