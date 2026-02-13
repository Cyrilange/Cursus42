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

void	print_status(t_philosopher *philo, t_message message)
{
	long	time;
	long	end;

	time = ft_get_time(MILLISECONDS) - philo->data->start_time;
	if (take_off_bool(&philo->protect_mutex, &philo->nbr_of_meals))
		return ;
	else
	{
		safety_mutex(&philo->data->protect_output, LOCK);
		end = take_off_bool(&philo->data->protect_data_races,
				&philo->data->is_finished);
		if ((message == TAKEN_LEFT_FORK || message == TAKEN_RIGHT_FORK) && !end)
			printf(ROSE"%ld philo %d is taking a fork\n"RESET, time, philo->id);
		else if (message == EATING && !end)
			printf(GREEN"%ld philo  %d is eating\n"RESET, time, philo->id);
		else if (message == SLEEPING && !end)
			printf(PURPLE"%ld philo  %d is sleeping\n"RESET, time, philo->id);
		else if (message == THINKING && !end)
			printf(BLUE"%ld philo  %d is thinking\n"RESET, time, philo->id);
		else if (message == DIED)
			printf(RED"%ld philo %d died\n"RESET, time, philo->id);
	}
	safety_mutex(&philo->data->protect_output, UNLOCK);
}

int	philo_is_eating(t_philosopher *philosopher)
{
	safety_mutex(&philosopher->left_fork->fork, LOCK);
	print_status(philosopher, TAKEN_LEFT_FORK);
	safety_mutex(&philosopher->right_fork->fork, LOCK);
	print_status(philosopher, TAKEN_RIGHT_FORK);
	set_value(&philosopher->protect_mutex,
		&philosopher->last_meal_time, ft_get_time(MILLISECONDS));
	philosopher->meals_counter++;
	print_status(philosopher, EATING);
	ft_usleep(philosopher->data, philosopher->data->time_to_eat);
	if (philosopher->data->meals_required > 0
		&& philosopher->meals_counter == philosopher->data->meals_required)
		no_repeat_mutexes(&philosopher->protect_mutex,
			&philosopher->nbr_of_meals, true);
	safety_mutex(&philosopher->left_fork->fork, UNLOCK);
	safety_mutex(&philosopher->right_fork->fork, UNLOCK);
	return (true);
}
