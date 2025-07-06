#include "philosophers.h"

static	void	*monitor_death(void *arg);



static void	ft_solo(t_philosopher *philosopher)
{
	print_status(philosopher, ROSE"has taken a fork"RESET);
	usleep(philosopher->data->time_to_die);
	print_status(philosopher, RED "died" RESET);
	safety_mutex(&philosopher->data->protect_mutex, LOCK);
	philosopher->data->is_finished = true;
	safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
}

void	executor(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	i = -1;
	data->start_time = ft_get_time();
	if (data->nbr_philo == 1)
	{
		ft_solo(data->philosophers);
		return ;
	}
	while (++i < data->nbr_philo)
		data->philosophers[i].last_meal_time = data->start_time;
	safety_phread(&monitor_thread, monitor_death, data, CREATE);
	i = -1;
	while (++i < data->nbr_philo)
		safety_phread(&data->philosophers[i].philo_thread,
			philosopher_routine, &data->philosophers[i], CREATE);
	safety_phread(&monitor_thread, NULL, NULL, JOIN);
	i = -1;
	while (++i < data->nbr_philo)
		safety_phread(&data->philosophers[i].philo_thread, NULL, NULL, JOIN);
}

void	*monitor_death(void *arg)
{
    t_data *data;
	int i;
	int full_count;

	data = (t_data *)arg;
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
