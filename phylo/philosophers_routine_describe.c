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
	philosopher_sleep(philosopher);
	philosopher_think(philosopher);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	
	safety_mutex(&philosopher->data->protect_mutex, LOCK);
	philosopher->last_meal_time = ft_get_time();
	safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
	
	// ⭐ SOLUTION OPTIMALE : Décalage calculé pour éviter la collision
	if (philosopher->data->nbr_philo > 1)
	{
		if (philosopher->id % 2 == 0)
		{
			ft_usleep(philosopher->data, philosopher->data->time_to_eat / 2);
		}
	}
	
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


static void philo_alone(t_philosopher *philosopher)
{
	safety_mutex(&philosopher->left_fork->fork, LOCK);
	print_status(philosopher, PURPLE"has taken a fork"RESET);
	ft_usleep(philosopher->data, philosopher->data->time_to_die);
	safety_mutex(&philosopher->left_fork->fork, UNLOCK);
}

void	philosopher_eat(t_philosopher *philosopher)
{
	t_fork	*first_fork;
	t_fork	*second_fork;

	if (philosopher->data->nbr_philo == 1)
	{
		philo_alone(philosopher);
		return ;
	}
	if (philosopher->left_fork->id_fork < philosopher->right_fork->id_fork)
	{
		first_fork = philosopher->left_fork;
		second_fork = philosopher->right_fork;
	}
	else
	{
		first_fork = philosopher->right_fork;
		second_fork = philosopher->left_fork;
	}
	safety_mutex(&philosopher->data->protect_mutex, LOCK);
	if (philosopher->data->meals_required > 0
		&& philosopher->meals_counter == philosopher->data->meals_required)
		{
			philosopher->is_full = true;
			safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
			return;
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
		return;
	}
	safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
	
	print_status(philosopher, BLUE "is sleeping   😴"RESET);
	ft_usleep(philosopher->data, philosopher->data->time_to_sleep);
}


void philosopher_think(t_philosopher *philosopher)
{
	//long think_time;

	safety_mutex(&philosopher->data->protect_mutex, LOCK);
	if (philosopher->data->is_finished)
	{
		safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
		return;
	}
	safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
	print_status(philosopher, GREEN"is thinking.  🤔"RESET);
	/* if (philosopher->data->nbr_philo % 2 == 1)
	{
		think_time = (philosopher->data->time_to_eat * 2) - philosopher->data->time_to_sleep;
		if (think_time > 0 && think_time < philosopher->data->time_to_die / 2)
			ft_usleep(philosopher->data, think_time);
		else
			ft_usleep(philosopher->data, philosopher->data->time_to_eat / 4);
	}
	else
	{
		usleep(90);
	}  */
}
