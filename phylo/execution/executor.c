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

void	ft_alone(t_philosopher *philosopher)
{
	print_status(philosopher, TAKEN_LEFT_FORK);
	ft_usleep(philosopher->data, philosopher->data->time_to_die);
	print_status(philosopher, DIED);
}

static bool	check_philosopher_death(t_philosopher *philo)
{
	long	now;
	long	last_meal;

	if (take_off_bool(&philo->protect_mutex, &philo->nbr_of_meals))
		return (false);
	now = ft_get_time(MILLISECONDS) -  take_off_long(&philo->protect_mutex, &philo->last_meal_time);
	last_meal = philo->data->time_to_die / 1000;
	if (now > last_meal)
		return (true);
	return (false);
}

static bool	all_philosophers_full(t_data *data)
{
	int	i;
	
	i = 0;
	while (i < data->nbr_philo)
	{
		if (!take_off_bool(&data->philosophers[i].protect_mutex,
						   &data->philosophers[i].nbr_of_meals))
			return (false);
		i++;
	}
	return (true);
}

void	*monitor_death(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = -1;
		while (++i < data->nbr_philo)
		{
			if (check_philosopher_death(&data->philosophers[i]))
			{
				no_repeat_mutexes(&data->protect_data_races, &data->someone_died, true);
				no_repeat_mutexes(&data->protect_data_races, &data->is_finished, true);
				print_status(&data->philosophers[i], DIED);
				return NULL;
			}
		}
		if (data->meals_required > 0 && all_philosophers_full(data))
		{
			no_repeat_mutexes(&data->protect_data_races, &data->is_finished, true);
			return NULL;
		}
		ft_usleep(data, 10);
	}
	return NULL;
}
