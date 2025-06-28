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

void *philosopher_routine(void *arg)
{
    t_philosopher *philosopher = (t_philosopher *)arg;
    t_data *data = philosopher->data;

    while (!data->is_finished)
    {
        safety_mutex(&philosopher->data->protect_mutex, LOCK);
        if (philosopher->data->is_finished)
        {
            safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
            break;
        }
        safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
        routine_from_philosophers(philosopher);
        if (data->meals_required > 0 && philosopher->meals_counter >= data->meals_required)
        {
            philosopher->is_full = true;
            data->is_finished = true;
            return NULL;
        }
        if (ft_get_time() - philosopher->last_meal_time > data->time_to_die)
        {
            printf(RED "Philosopher %d has died.\n" RESET, philosopher->id);
            data->is_finished = true;
            return NULL;
        }
    }
    return NULL;
}

static void  philo_alone(t_data *data)
{

    usleep(data->time_to_die * 1000);
    printf("Philosopher %d has died.\n", 1);
    data->philosophers[0].is_full = true;
    safety_mutex(&data->protect_mutex, LOCK);
    data->is_finished = true;
    safety_mutex(&data->protect_mutex, UNLOCK);
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