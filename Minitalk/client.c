/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-12 15:55:17 by csalamit          #+#    #+#             */
/*   Updated: 2024-10-12 15:55:17 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char str)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((str >> bit) & 1)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(600);
		bit++;
	}
}

int	main(int ac, char **ar)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(ar[1]);
		while (ar[2][i] != '\0')
		{
			send_signal(pid, ar[2][i]);
			i++;
		}
		send_signal(pid, '\0');
	}
	else
	{
		write(1, "./client <PID_number> <message>\n", 32);
		return (1);
	}
	return (0);
}
