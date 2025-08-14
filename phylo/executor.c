#include "philosophers.h"

static	void	*monitor_death(void *arg);

void	executor(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	i = -1;
	data->start_time = ft_get_time();
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
    int		i;
	long	last_meal;
	t_data *data;

	data = (t_data *)arg;


	i = -1;
	while (++i < data->nbr_philo)
	{
		safety_mutex(&data->protect_mutex, LOCK);
		last_meal = data->philosophers[i].last_meal_time;
		safety_mutex(&data->protect_mutex, UNLOCK);
		if (data->time_to_die < (ft_get_time() - last_meal))
		{
			safety_mutex(&data->protect_mutex, LOCK);
			data->is_finished = true;
			safety_mutex(&data->protect_mutex, UNLOCK);
			print_status(&data->philosophers[i], RED "died " EMOJI_SKULL RESET);
			break ;
		}
	}
	return (NULL);
}
