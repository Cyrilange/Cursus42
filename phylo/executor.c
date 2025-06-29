#include "philosophers.h"

long ft_get_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000); // Return time in milliseconds
}

static void routine_from_philosophers(t_philosopher *philosopher)
{
    philosopher_eat(philosopher);
    philosopher_sleep(philosopher);
    philosopher_think(philosopher);
}

static void  philo_alone(t_data *data)
{

    safety_mutex(&data->protect_mutex, LOCK);
    data->philosophers[0].last_meal_time = ft_get_time();
    safety_mutex(&data->protect_mutex, UNLOCK);
    usleep(data->time_to_die * 1000);
    safety_mutex(&data->protect_mutex, LOCK);
    print_status(data->philosophers, "has died.\n" RESET); // Time is 0 as per example output
    data->philosophers[0].is_full = true; // Mark as full if single philosopher logic implies
    data->is_finished = true;
    safety_mutex(&data->protect_mutex, UNLOCK);
}


void	*philosopher_routine(void *arg)
{
    t_philosopher *philosopher;

    philosopher = (t_philosopher *)arg;
    while (1)
    {
        safety_mutex(&philosopher->data->protect_mutex, LOCK);
        if (philosopher->data->is_finished || philosopher->is_full)
        {
            safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
            break;
        }
        safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
        routine_from_philosophers(philosopher);
    }
    return NULL;
}




void    executor(t_data *data)
{
    int i;

    i = 0;
    data->start_time = ft_get_time();
    if (data->nbr_philo == 0)
        return ;
    else if (data->nbr_philo == 1)
    {
        philo_alone(data);
        return;
    }
    else
    {
        while (i < data->nbr_philo)
        {
            safety_phread(&data->philosophers[i].philo_thread, philosopher_routine, &data->philosophers[i], CREATE);
            i++;
        }
        i = 0;
        while (i < data->nbr_philo)
        {
            safety_phread(&data->philosophers[i].philo_thread, NULL, NULL, JOIN);
            i++;
        }
    }            
}