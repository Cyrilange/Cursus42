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
	long	time_left;
	bool	finished;

	start = ft_get_time();
	current_time = start;
	while ((current_time - start) < time_in_ms)
	{
		safety_mutex(&data->protect_mutex, LOCK);
		finished = data->is_finished;
		safety_mutex(&data->protect_mutex, UNLOCK);
		if (finished)
			return ;
		current_time = ft_get_time();
		time_left = time_in_ms - (current_time - start);
		if (time_left <= 100)
		{
			while ((ft_get_time() - start) < time_in_ms)
				;
			break ;
		}
		usleep(10);
		current_time = ft_get_time();
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
