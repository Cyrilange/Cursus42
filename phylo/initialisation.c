/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-13 16:06:05 by csalamit          #+#    #+#             */
/*   Updated: 2025-07-13 16:06:05 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	initialisation_forks(t_philosopher *philosophers,
	t_fork *forks, int id_philo)
{
	int	number_philosophers;

	number_philosophers = philosophers->data->nbr_philo;
	if (philosophers->id % 2 == 0)
	{
		philosophers->right_fork = &forks[id_philo];
		philosophers->left_fork = &forks[(id_philo + 1) % number_philosophers];
	}
	else
	{
		philosophers->left_fork = &forks[id_philo];
		philosophers->right_fork = &forks[(id_philo + 1) % number_philosophers];
	}
}

static void	philosophers_initialisation(t_data *data)
{
	int				i;
	t_philosopher	*philosophers;

	i = 0;
	while (i < data->nbr_philo)
	{
		philosophers = data->philosophers + i;
		philosophers->id = i + 1;
		philosophers->meals_counter = 0;
		philosophers->is_full = false;
		philosophers->data = data;
		initialisation_forks(philosophers, data->forks, i);
		i++;
	}
}

bool	check_all_philos_full(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (!data->philosophers[i].is_full)
			return (false);
		i++;
	}
	return (true);
}

void	ft_initialisation(t_data *data)
{
	int	i;

	i = 0;
	data->is_finished = false;
	data->someone_died = false;
	data->forks = check_malloc(sizeof(t_fork) * data->nbr_philo);
	data->philosophers = check_malloc(sizeof(t_philosopher) * data->nbr_philo);
	safety_mutex(&data->protect_mutex, INIT);
	while (i < data->nbr_philo)
	{
		data->forks[i].id_fork = i;
		safety_mutex(&data->forks[i].fork, INIT);
		i++;
	}
	philosophers_initialisation(data);
}
