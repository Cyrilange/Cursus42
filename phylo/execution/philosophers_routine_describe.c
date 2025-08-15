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

// helper pour incrémenter une valeur protégée par mutex
void helper_philo_eat(t_mutex *mut, long *value)
{
    safety_mutex(mut, LOCK);
    (*value)++;
    safety_mutex(mut, UNLOCK);
}

void philosopher_eat(void *arg)
{
    t_philosopher *philo = (t_philosopher *)arg;

    // Attente du démarrage de la simulation
    while (!take_off_bool(&philo->data->protect_data_races, &philo->data->is_ready))
        ;

    // Marquer le philosophe comme mangeant
    set_value(&philo->protect_mutex, &philo->is_eating, true);
    philo->last_meal_time = ft_get_time(MILLISECONDS);

    helper_philo_eat(&philo->data->protect_data_races, &philo->data->philo_running);

    // Décalage pour alterner les philosophes pairs/impairs
    if (philo->id % 2 == 0)
        ft_usleep(philo->data, philo->data->time_to_eat / 2);
    else
        print_status(philo, THINKING);

    while (!take_off_bool(&philo->data->protect_data_races, &philo->data->is_finished))
    {
        philo_is_eating(philo);
        print_status(philo, SLEEPING);
        ft_usleep(philo->data, philo->data->time_to_sleep);
        philosopher_think(philo, false);
    }
}

void philosopher_think(t_philosopher *philo, bool routine_think)
{
    long eat_t = philo->data->time_to_eat;
    long sleep_t = philo->data->time_to_sleep;
    long think_t;

    if (philo->data->is_ready)
        print_status(philo, THINKING);

    if (philo->data->nbr_philo % 2 == 0)
        return;

    think_t = (eat_t * 2) - sleep_t;
    if (think_t < 0)
        think_t = 0;

    ft_usleep(philo->data, think_t * 0.3);
}

void routine(t_data *data)
{
    int i = 0;

    if (data->meals_required == 0)
        return;

    if (data->nbr_philo == 1)
    {
        ft_alone(data->philosophers);
        return;
    }

    while (i < data->nbr_philo)
    {
        safety_phread(&data->philosophers[i].philo_thread,
                      philosopher_eat,
                      &data->philosophers[i], CREATE);
        i++;
    }

    safety_phread(&data->philo_death, monitor_death, data, CREATE);
    data->start_time = ft_get_time(MILLISECONDS);
    take_off_bool(&data->protect_data_races, &data->is_finished);

    i = 0;
    while (i < data->nbr_philo)
        safety_phread(&data->philosophers[i++].philo_thread, NULL, NULL, JOIN);

    no_repeat_mutexes(&data->protect_data_races, &data->philo_death, true);
    safety_phread(&data->philo_death, NULL, NULL, JOIN);
}
