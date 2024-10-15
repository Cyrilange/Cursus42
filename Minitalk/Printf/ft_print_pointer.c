/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-28 09:04:44 by csalamit          #+#    #+#             */
/*   Updated: 2024-05-28 09:04:44 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_print_pointer(void *ptr)
{
	const char			*prefix;
	long long			len;
	unsigned long long	address;

	if (ptr == 0)
		return (ft_putstr("(nil)"));
	prefix = "0x";
	len = ft_putstr(prefix);
	address = (unsigned long long)ptr;
	len += ft_hex_lowercase(address);
	return (len);
}
