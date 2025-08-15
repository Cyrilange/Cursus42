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

#include "../philosophers.h"

#include <string.h>

void	print_status(t_philosopher *philo, t_message message)
{
	long	time;
	long	end;

	time = ft_get_time(MILLISECONDS) - philo->data->start_time;
	if (take_off_bool(&philo->protect_mutex, &philo->is_full))
		return ;
	else
	{
		safety_mutex(&philo->data->protect_output, LOCK);
		end = take_off_bool(&philo->data->protect_data_races, &philo->data->is_finished);
		if ((message == TAKEN_LEFT_FORK || message == TAKEN_RIGHT_FORK) && (!end))
			printf(ROSE"%ld "RESET"%d is taking a fork\n", time, philo->id);
		if (message == EATING && (!end))
			printf(GREEN"%ld "RESET " %d is eating\n", time, philo->id);
		if (message == SLEEPING && (!end))
			printf(PURPLE"%ld " RESET" %d is sleeping\n", time, philo->id);
		if (message == THINKING && (!end))
			printf(BLUE"%ld "RESET " %d is thinking\n", time, philo->id);
		if (message == DIED && (!end))
			printf(RED"%ld "RESET " %d died\n", time, philo->id);
	}
	safety_mutex(&philo->data->protect_output, UNLOCK);
}
int	philo_is_eating(t_philosopher *philosopher)
{
	safety_mutex(&philosopher->left_fork->fork, LOCK);
	print_status(philosopher, TAKEN_LEFT_FORK);
	safety_mutex(&philosopher->right_fork->fork, LOCK);
	print_status(philosopher, TAKEN_RIGHT_FORK);
	set_value(&philosopher->protect_mutex, &philosopher->last_meal_time, ft_get_time(MILLISECONDS));
	philosopher->meals_counter++;
	print_status(philosopher, EATING);
	ft_usleep(philosopher->data, philosopher->data->time_to_eat);
	no_repeat_mutexes(&philosopher->left_fork->fork, &philosopher->is_eating, true);
	if (philosopher->data->meals_required > 0 && philosopher->meals_counter == philosopher->data->meals_required)
	no_repeat_mutexes(&philosopher->protect_mutex, &philosopher->is_full, true);
	safety_mutex(&philosopher->left_fork->fork, UNLOCK);
	safety_mutex(&philosopher->right_fork->fork, UNLOCK);
	return (true);
}
