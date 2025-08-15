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
#include "../philosophers.h"

void ft_alone(t_philosopher *philosopher)
{
    print_status(philosopher, TAKEN_LEFT_FORK);
    ft_usleep(philosopher->data, philosopher->data->time_to_die);
    print_status(philosopher, DIED);
}

static bool check_philosopher_death(t_philosopher *philo)
{
    long now = ft_get_time(MILLISECONDS);
    long last_meal;

    last_meal = take_off_long(&philo->protect_mutex, &philo->last_meal_time);
    if (now - last_meal > philo->data->time_to_die)
        return (true);
    return (false);
}

void *monitor_death(void *arg)
{
    t_data *data = (t_data *)arg;
    long i;

    while (!take_off_bool(&data->protect_data_races, &data->someone_died))
    {
        i = 0;
        while (i < data->nbr_philo)
        {
            if (check_philosopher_death(&data->philosophers[i]))
            {
                // On met à jour le booléen directement
                safety_mutex(&data->protect_data_races, LOCK);
                data->someone_died = true;
                safety_mutex(&data->protect_data_races, UNLOCK);

                print_status(&data->philosophers[i], DIED);
                return (NULL);
            }
            i++;
        }
        ft_usleep(data, 1); // pause pour éviter CPU 100%
    }
    return (NULL);
}
