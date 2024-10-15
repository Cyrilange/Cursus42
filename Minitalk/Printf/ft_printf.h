/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-28 09:07:49 by csalamit          #+#    #+#             */
/*   Updated: 2024-05-28 09:07:49 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
int		ft_putchar(int c);
int		ft_putnbr(int nb);
int		ft_putstr(const char *str);
int		ft_unsigned_nbr(unsigned int n);
long	ft_print_pointer(void *ptr);
int		ft_hex_upper(unsigned long long num);
int		ft_hex_lowercase(unsigned long long num);

#endif
