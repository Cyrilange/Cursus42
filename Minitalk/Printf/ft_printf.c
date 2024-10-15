/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-28 09:04:52 by csalamit          #+#    #+#             */
/*   Updated: 2024-05-28 09:04:52 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list *args, const char format)
{
	int	frt;

	frt = 0;
	if (format == 'c')
		frt = frt + ft_putchar(va_arg(*args, int));
	if (format == 's')
		frt = frt + ft_putstr(va_arg(*args, char *));
	if (format == 'u')
		frt = frt + ft_unsigned_nbr(va_arg(*args, unsigned int));
	if (format == 'x')
		frt = frt + ft_hex_lowercase(va_arg(*args, unsigned int));
	if (format == 'X')
		frt = frt + ft_hex_upper(va_arg(*args, unsigned int));
	if (format == 'i' || format == 'd')
		frt = frt + ft_putnbr(va_arg(*args, int));
	if (format == 'p')
		frt = frt + ft_print_pointer(va_arg(*args, void *));
	if (format == '%')
		frt = frt + ft_putchar('%');
	return (frt);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_len;
	int		i;

	total_len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			total_len += ft_format(&args, format[i]);
		}
		else
		{
			ft_putchar(format[i]);
			total_len++;
		}
		i++;
	}
	va_end(args);
	return (total_len);
}

/* #include <stdio.h>

int main()
{
	char c = 'a';
	char *str = "le chien est mort";
	void *ptr;
	char *y = NULL;
	ptr = &y;
	int z = -2147483648;
    int x = 442;
	
    
	
	
	
	int ori = (printf("-510"));
	int myori = (ft_printf("-50"));
	int ori2 = (printf("510"));
	int myori2 = (ft_printf("50"));

    //my printf
    printf("\nmyprintf\n\n");
	
	ft_printf("Character: %c\n", c);
	ft_printf("String: %s\n", str);
	ft_printf("Pointer: %p\n", str);
	ft_printf("Pointer: %p\n", &y);
	ft_printf("decimal: %d\n", z);
	ft_printf("Unsigned: %u\n", 0);
	ft_printf("Hexadecimal (lower): %x\n", z);
    ft_printf("Hexadecimal (upper): %X\n", x);
    ft_printf("Percent: %%\n");

	ft_printf("%u : %u : %u\n", ori, x, myori);
	ft_printf("%u : %u\n", ori2, myori2);
    
    //reel printf
    printf("\noriginal\n\n");
	
	printf("Character: %c\n", c);
	printf("String: %s\n", str);
	printf("Pointer: %p\n", str);
	printf("Pointer: %p\n", &y);
	printf("decimal: %d\n", z);
    printf("Unsigned: %u\n", 0);
    printf("Hexadecimal (lower): %x\n", z);
    printf("Hexadecimal (upper): %X\n", x);
    printf("Percent: %%\n");
    
	printf("%u: %u : %u\n", ori,x,  myori);
	printf("%u : %u\n", ori2, myori2);

    return 0;
} */