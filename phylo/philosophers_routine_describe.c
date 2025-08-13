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

#include "philosophers.h"

static void	routine_from_philosophers(t_philosopher *philosopher)
{
	philosopher_eat(philosopher);
	if (it_started_or_not(philosopher) || philosopher->is_full)
		return ;
	philosopher_sleep(philosopher);
	if (it_started_or_not(philosopher) || philosopher->is_full)
		return ;
	philosopher_think(philosopher);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	if (philosopher->data->nbr_philo > 1)
		ft_usleep(philosopher->data, (philosopher->id % 3) * 10);
	while (1)
	{
		safety_mutex(&philosopher->data->protect_mutex, LOCK);
		if (philosopher->data->is_finished || philosopher->is_full)
		{
			safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
			break ;
		}
		if (philosopher->data->meals_required != -1
			&& philosopher->meals_counter >= philosopher->data->meals_required)
		{
			philosopher->is_full = true;
			safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
			break ;
		}
		safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
		routine_from_philosophers(philosopher);
	}
	return (NULL);
}

static void	ft_helper_eat(t_philosopher *philosopher,
	t_fork **first_fork, t_fork **second_fork)
{
	if (philosopher->left_fork->id_fork < philosopher->right_fork->id_fork)
	{
		*first_fork = philosopher->right_fork;
		*second_fork = philosopher->left_fork;
	}
	else
	{
		*first_fork = philosopher->left_fork;
		*second_fork = philosopher->right_fork;
	}
}

void	philosopher_eat(t_philosopher *philosopher)
{
	t_fork	*first_fork;
	t_fork	*second_fork;

	if (philosopher->data->nbr_philo == 1)
		ft_alone(philosopher);
	if (philosopher->data->nbr_philo % 2 == 1
		&& philosopher->id == philosopher->data->nbr_philo)
	{
		first_fork = philosopher->right_fork;
		second_fork = philosopher->left_fork;
	}
	else
		ft_helper_eat(philosopher, &first_fork, &second_fork);
	safety_mutex(&philosopher->data->protect_mutex, LOCK);
	if (philosopher->data->meals_required > 0
		&& philosopher->meals_counter == philosopher->data->meals_required)
	{
		philosopher->is_full = true;
		safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
		return ;
	}
	safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
	philo_is_eating(philosopher, first_fork, second_fork);
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	safety_mutex(&philosopher->data->protect_mutex, LOCK);
	if (philosopher->data->is_finished)
	{
		safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
		return ;
	}
	safety_mutex(&philosopher->data->protect_mutex, UNLOCK);	
	print_status(philosopher, BLUE "is sleeping   😴"RESET);
	ft_usleep(philosopher->data, philosopher->data->time_to_sleep);
}

void	philosopher_think(t_philosopher *philosopher)
{
	long	time_left;
	long	time_think;

	time_left = philosopher->data->time_to_die
		- (ft_get_time() - philosopher->last_meal_time);
	safety_mutex(&philosopher->data->protect_mutex, LOCK);
	if (philosopher->data->is_finished)
	{
		safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
		return ;
	}
	safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
	print_status(philosopher, GREEN "is thinking.  🤔" RESET);
	if (time_left <= philosopher->data->time_to_eat + 5)
		return ;
	time_think = time_left - philosopher->data->time_to_eat
		- philosopher->data->time_to_sleep - 5;
	if (time_think < 0)
		time_think = 0;
	ft_usleep(philosopher->data, time_think);
}
