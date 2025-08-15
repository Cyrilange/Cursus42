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
