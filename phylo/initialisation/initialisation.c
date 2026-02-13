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

#include "../philosophers.h"

static void	initialisation_forks(t_philosopher *philosophers,
	t_fork	*forks, int id_philo)
{
	int	number_philosophers;

	number_philosophers = philosophers->data->nbr_philo;
	if (philosophers->id % 2 == 0)
	{
		philosophers->left_fork = &forks[id_philo];
		philosophers->right_fork = &forks[(id_philo + 1) % number_philosophers];
	}
	else
	{
		philosophers->left_fork = &forks[(id_philo + 1) % number_philosophers];
		philosophers->right_fork = &forks[id_philo];
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
		philosophers->nbr_of_meals = false;
		philosophers->meals_counter = 0;
		philosophers->is_full = false;
		philosophers->last_meal_time = data->start_time;
		safety_mutex(&philosophers->protect_mutex, INIT);
		philosophers->data = data;
		initialisation_forks(philosophers, data->forks, i);
		i++;
	}
}

void	ft_initialisation(t_data *data)
{
	int	i;

	i = 0;
	data->is_finished = false;
	data->someone_died = false;
	data->is_ready = false;
	data->philo_running = 0;
	data->forks = check_malloc(sizeof(t_fork) * data->nbr_philo);
	data->philosophers = check_malloc(sizeof(t_philosopher) * data->nbr_philo);
	safety_mutex(&data->protect_data_races, INIT);
	safety_mutex(&data->protect_output, INIT);
	while (i < data->nbr_philo)
	{
		safety_mutex(&data->forks[i].fork, INIT);
		data->forks[i].id_fork = i;
		i++;
	}
	philosophers_initialisation(data);
}
