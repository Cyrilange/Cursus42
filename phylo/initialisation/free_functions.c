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

#include "../philosophers.h"

static void	clear_data(t_data *data)
{
	if (data->forks)
		free(data->forks);
	if (data->philosophers)
		free(data->philosophers);
}

long	ft_get_time(t_unit unit)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (unit == SECONDS)
		return (tv.tv_sec + (tv.tv_usec / 1000000));
	else if (unit == MILLISECONDS)
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	else if (unit == MICROSECONDS)
		return ((tv.tv_sec * 1000000) + tv.tv_usec);
	error_function("Error: Invalid time unit specified.");
	return (-1);
}

void	ft_exit(t_data *data)
{
	long	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		safety_mutex(&data->forks[i].fork, DESTROY);
	}
	safety_mutex(&data->protect_data_races, DESTROY);
	clear_data(data);
}
