/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-13 16:06:02 by csalamit          #+#    #+#             */
/*   Updated: 2025-07-13 16:06:02 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	clear_data(t_data *data)
{
	if (data->forks)
		free(data->forks);
	if (data->philosophers)
		free(data->philosophers);
}

void	ft_usleep(t_data *data, long time_in_ms)
{
	long	start;
	long	current_time;

	start = ft_get_time();
	current_time = start;
	while ((current_time - start) < time_in_ms)
	{
		current_time = ft_get_time();
		if (data->is_finished)
		{
			return ;
		}
		if (time_in_ms - (current_time - start) <= 100)
		{
			while ((current_time - start) < time_in_ms)
				current_time = ft_get_time();
			break ;
		}
		usleep(10);
	}
}

void	ft_exit(t_data *data)
{
	long	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		safety_mutex(&data->forks[i].fork, DESTROY);
	}
	safety_mutex(&data->protect_mutex, DESTROY);
	clear_data(data);
}
