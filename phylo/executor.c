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

static	void	*monitor_death(void *arg);

static void	ft_solo(t_philosopher *philosopher)
{
	print_status(philosopher, ROSE"has taken a fork"RESET);
	usleep(philosopher->data->time_to_die);
	print_status(philosopher, RED "died " EMOJI_SKULL RESET);
	safety_mutex(&philosopher->data->protect_mutex, LOCK);
	philosopher->data->is_finished = true;
	safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
}

void	executor(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	i = -1;
	data->start_time = ft_get_time();
	if (data->nbr_philo == 1)
	{
		ft_solo(data->philosophers);
		return ;
	}
	while (++i < data->nbr_philo)
		data->philosophers[i].last_meal_time = data->start_time;
	usleep(1);
	safety_phread(&monitor_thread, monitor_death, data, CREATE);
	i = -1;
	while (++i < data->nbr_philo)
		safety_phread(&data->philosophers[i].philo_thread,
			philosopher_routine, &data->philosophers[i], CREATE);
	safety_phread(&monitor_thread, NULL, NULL, JOIN);
	i = -1;
	while (++i < data->nbr_philo)
		safety_phread(&data->philosophers[i].philo_thread, NULL, NULL, JOIN);
}

static bool	check_philosopher_death(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		if (ft_get_time()
			- data->philosophers[i].last_meal_time > data->time_to_die)
		{
			print_status(&data->philosophers[i], RED "died 💀" RESET);
			safety_mutex(&data->protect_mutex, LOCK);
			data->is_finished = true;
			safety_mutex(&data->protect_mutex, UNLOCK);
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

void	*monitor_death(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_philosopher_death(data) || check_all_full(data))
			break ;
		usleep(1);
	}
	return (NULL);
}
