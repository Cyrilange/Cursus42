/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 16:13:04 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 16:13:04 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(const char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_atol(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1 ;
	while ((str[i] == 32) || (str[i] <= 13 && str[i] >= 9))
	{
		i++;
	}
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "Usage: ./program <number>\n", 25);
        return (1);
    }

    long result = ft_atol(argv[1]);
    ft_putnbr(result);
    write(1, "\n", 1);
    return (0);
}
*/