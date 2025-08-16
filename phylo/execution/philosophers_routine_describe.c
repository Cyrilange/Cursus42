/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine_describe.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-13 15:42:11 by csalamit          #+#    #+#             */
/*   Updated: 2025-07-13 15:42:11 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	helper_philo_eat(t_mutex *mut, long *value)
{
	safety_mutex(mut, LOCK);
	(*value)++;
	safety_mutex(mut, UNLOCK);
}

void	*philosopher_eat(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (!take_off_bool(&philo->data->protect_data_races,
			&philo->data->is_ready))
		;
	if (philo->data->nbr_philo % 2 != 0)
		ft_usleep(philo->data, philo->id * 10);
	set_value(&philo->protect_mutex, &philo->last_meal_time,
		ft_get_time(MILLISECONDS));
	while (!take_off_bool(&philo->data->protect_data_races,
			&philo->data->is_finished))
	{
		if (take_off_bool(&philo->protect_mutex, &philo->nbr_of_meals))
			break ;
		philo_is_eating(philo);
		print_status(philo, SLEEPING);
		ft_usleep(philo->data, philo->data->time_to_sleep);
		philosopher_think(philo, false);
	}
	return (NULL);
}

void	philosopher_think(t_philosopher *philo, bool routine_start)
{
	long	eat_t;
	long	sleep_t;
	long	think_t;

	sleep_t = philo->data->time_to_sleep;
	eat_t = philo->data->time_to_eat;
	if (!routine_start)
		print_status(philo, THINKING);
	if (philo->data->nbr_philo % 2 == 0)
		return ;
	else
	{
		think_t = (eat_t * 2) - sleep_t;
		if (think_t < 0)
			think_t = 0;
		ft_usleep(philo->data, think_t);
	}
}

void	routine(t_data *data)
{
	int	i;

	if (data->nbr_philo == 1)
	{
		ft_alone(data->philosophers);
		return ;
	}
	data->start_time = ft_get_time(MILLISECONDS);
	i = -1;
	while (++i < data->nbr_philo)
		set_value(&data->philosophers[i].protect_mutex,
			&data->philosophers[i].last_meal_time,
			data->start_time);
	i = -1;
	while (++i < data->nbr_philo)
		safety_phread(&data->philosophers[i].philo_thread,
			philosopher_eat, &data->philosophers[i], CREATE);
	no_repeat_mutexes(&data->protect_data_races, &data->is_ready, true);
	safety_phread(&data->philo_death, monitor_death, data, CREATE);
	i = -1;
	while (++i < data->nbr_philo)
		safety_phread(&data->philosophers[i].philo_thread, NULL, NULL, JOIN);
	no_repeat_mutexes(&data->protect_data_races, &data->is_finished, true);
	safety_phread(&data->philo_death, NULL, NULL, JOIN);
}
