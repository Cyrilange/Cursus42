/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-13 15:42:23 by csalamit          #+#    #+#             */
/*   Updated: 2025-07-13 15:42:23 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

#include <string.h>

void	print_status(t_philosopher *philo, const char *message)
{
	long	timestamp;
	bool	someone_died_local;

	safety_mutex(&philo->data->protect_mutex, LOCK);
	someone_died_local = philo->data->someone_died;
	timestamp = ft_get_time() - philo->data->start_time;
	safety_mutex(&philo->data->protect_mutex, UNLOCK);
	if (!someone_died_local)
		printf("%ld philosopher %d %s\n", timestamp, philo->id, message);
}

bool	it_started_or_not(t_philosopher *philosopher)
{
	bool	finished;

	safety_mutex(&philosopher->data->protect_mutex, LOCK);
	finished = philosopher->data->is_finished;
	safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
	return (finished);
}

static void	set_eating_status(t_philosopher *philosopher, bool status)
{
	safety_mutex(&philosopher->data->protect_mutex, LOCK);
	philosopher->is_eating = status;
	if (status)
		philosopher->last_meal_time = ft_get_time();
	safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
}

void	philo_is_eating(t_philosopher *philosopher,
		t_fork *first_fork, t_fork *second_fork)
{
	if (it_started_or_not(philosopher))
		return ;
	safety_mutex(&first_fork->fork, LOCK);
	print_status(philosopher, PURPLE "has taken a fork" RESET);
	safety_mutex(&second_fork->fork, LOCK);
	print_status(philosopher, ROSE "has taken a fork" RESET);
	set_eating_status(philosopher, true);
	print_status(philosopher, YELLOW "is eating" RESET);
	ft_usleep(philosopher->data, philosopher->data->time_to_eat);
	safety_mutex(&philosopher->data->protect_mutex, LOCK);
	philosopher->meals_counter++;
	safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
	set_eating_status(philosopher, false);
	safety_mutex(&second_fork->fork, UNLOCK);
	safety_mutex(&first_fork->fork, UNLOCK);
}
