/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-13 16:05:55 by csalamit          #+#    #+#             */
/*   Updated: 2025-07-13 16:05:55 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*monitor_death(void *arg);

void	ft_alone(t_philosopher *philosopher)
{
	safety_mutex(&philosopher->left_fork->fork, LOCK);
	print_status(philosopher, PURPLE"has taken a fork"RESET);
	ft_usleep(philosopher->data, philosopher->data->time_to_die);
	safety_mutex(&philosopher->left_fork->fork, UNLOCK);
	print_status(philosopher, RED "died " EMOJI_SKULL RESET);
	safety_mutex(&philosopher->data->protect_mutex, LOCK);
	philosopher->data->is_finished = true;
	safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
}

void	executor(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	data->start_time = ft_get_time();
	if (data->nbr_philo == 1)
	{
		ft_alone(data->philosophers);
		return ;
	}
	i = 0;
	while (i < data->nbr_philo)
		data->philosophers[i++].last_meal_time = data->start_time;
	usleep(10);
	safety_phread(&monitor_thread, monitor_death, data, CREATE);
	i = 0;
	while (i < data->nbr_philo)
	{
		safety_phread(&data->philosophers[i].philo_thread,
			philosopher_routine, &data->philosophers[i], CREATE);
		i++;
	}
	i = 0;
	while (i < data->nbr_philo)
		safety_phread(&data->philosophers[i++].philo_thread, NULL, NULL, JOIN);
	safety_phread(&monitor_thread, NULL, NULL, JOIN);
}

static bool	check_philosopher_death(t_data *data)
{
	int		i;
	long	last_meal;
	bool	is_eating;
	bool	someone_died_loc;

	i = -1;
	while (++i < data->nbr_philo)
	{
		safety_mutex(&data->protect_mutex, LOCK);
		last_meal = data->philosophers[i].last_meal_time;
		is_eating = data->philosophers[i].is_eating;
		someone_died_loc = data->someone_died;
		safety_mutex(&data->protect_mutex, UNLOCK);
		if (!someone_died_loc && !is_eating
			&& data->time_to_die < (ft_get_time() - last_meal))
		{
			safety_mutex(&data->protect_mutex, LOCK);
			data->someone_died = true;
			data->is_finished = true;
			safety_mutex(&data->protect_mutex, UNLOCK);
			print_status(&data->philosophers[i], RED "died " EMOJI_SKULL RESET);
			return (true);
		}
	}
	return (false);
}

static bool	check_all_full(t_data *data)
{
	if (data->meals_required <= 0)
		return (false);
	if (check_all_philos_full(data))
	{
		safety_mutex(&data->protect_mutex, LOCK);
		data->is_finished = true;
		safety_mutex(&data->protect_mutex, UNLOCK);
		return (true);
	}
	return (false);
}

static void	*monitor_death(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_all_full(data))
			break ;
		else if (check_philosopher_death(data))
			break ;
		usleep(1000);
	}
	return (NULL);
}
