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

#include <string.h> // nécessaire pour strstr()

void print_status(t_philosopher *philo, const char *message)
{
    long timestamp;

    safety_mutex(&philo->data->protect_mutex, LOCK);
    if (!philo->data->someone_died)
    {
        timestamp = ft_get_time() - philo->data->start_time;
        printf("%ld philosopher %d %s\n", timestamp, philo->id, message);
    }
    safety_mutex(&philo->data->protect_mutex, UNLOCK);
}

void philo_is_eating(t_philosopher *philosopher, t_fork *first_fork, t_fork *second_fork)
{
    safety_mutex(&philosopher->data->protect_mutex, LOCK);
    if (philosopher->data->is_finished)
    {
        safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
        return;
    }
    safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
    safety_mutex(&first_fork->fork, LOCK);
    print_status(philosopher, PURPLE"has taken a fork"RESET);   
    safety_mutex(&philosopher->data->protect_mutex, LOCK);
    if (philosopher->data->is_finished)
    {
        safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
        safety_mutex(&first_fork->fork, UNLOCK);
        return;
    }
    safety_mutex(&philosopher->data->protect_mutex, UNLOCK);  
    safety_mutex(&second_fork->fork, LOCK);
    print_status(philosopher, ROSE"has taken a fork"RESET);
    safety_mutex(&philosopher->data->protect_mutex, LOCK);
    philosopher->last_meal_time = ft_get_time();
    safety_mutex(&philosopher->data->protect_mutex, UNLOCK); 
    print_status(philosopher, YELLOW "is eating"RESET);
    ft_usleep(philosopher->data, philosopher->data->time_to_eat);
    safety_mutex(&philosopher->data->protect_mutex, LOCK);
    philosopher->meals_counter++;
    safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
    safety_mutex(&second_fork->fork, UNLOCK);
    safety_mutex(&first_fork->fork, UNLOCK);
}