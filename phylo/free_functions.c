#include "philosophers.h"


static void	clear_data(t_data *data)
{
	if (data->forks)
		free(data->forks);
	if (data->philosophers)
		free(data->philosophers);
}

void	ft_usleep(long time_in_ms)
{
	long	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time_in_ms)
		usleep(100);
}

void	ft_exit(t_data *data)
{
	long	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		safety_mutex(&data->forks[i].fork, DESTROY);
	}
	safety_mutex(&data->protect_mutex, DESTROY);
	clear_data(data);
}
