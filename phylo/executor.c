#include "philosophers.h"

static void *monitor_death(void *arg);

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

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	while (1)
	{
		safety_mutex(&philosopher->data->protect_mutex, LOCK);
		if (philosopher->data->is_finished || philosopher->is_full)
		{
			safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
			break;
		}
		if (philosopher->data->meals_required != -1 && philosopher->meals_counter >= philosopher->data->meals_required)
		{
			philosopher->is_full = true;
			safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
			break;
		}
		safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
		routine_from_philosophers(philosopher);
	}
	return (NULL);
}

void executor(t_data *data)
{
    int i;
    pthread_t monitor_thread;

    i = -1;
    data->start_time = ft_get_time();
    while (++i < data->nbr_philo)
        data->philosophers[i].last_meal_time = data->start_time;
    safety_phread(&monitor_thread, monitor_death, data, CREATE);
    i = -1;
    while (++i < data->nbr_philo)
        safety_phread(&data->philosophers[i].philo_thread, philosopher_routine, &data->philosophers[i], CREATE);
    safety_phread(&monitor_thread, NULL, NULL, JOIN);
    i = -1;
    while (++i < data->nbr_philo)
        safety_phread(&data->philosophers[i].philo_thread, NULL, NULL, JOIN);
}

void *monitor_death(void *arg)
{
    t_data *data = (t_data *)arg;
    int i;
    int full_count;

    while (1)
    {
        i = -1;
        full_count = 0;
        while (++i < data->nbr_philo)
        {
            if (ft_get_time() - data->philosophers[i].last_meal_time > data->time_to_die)
            {
                print_status(&data->philosophers[i], RED "died" RESET);
                safety_mutex(&data->protect_mutex, LOCK);
                data->is_finished = true;
                safety_mutex(&data->protect_mutex, UNLOCK);
                return NULL;
            }
            if (data->philosophers[i].is_full)
                full_count++;
        }
        if (data->meals_required > 0 && full_count == data->nbr_philo)
        {
            safety_mutex(&data->protect_mutex, LOCK);
            data->is_finished = true;
            safety_mutex(&data->protect_mutex, UNLOCK);
            return NULL;
        }
        usleep(1000);
    }
    return NULL;
}
