#include "philosophers.h"

static void	routine_from_philosophers(t_philosopher *philosopher)
{
	philosopher_eat(philosopher);
	philosopher_sleep(philosopher);
	philosopher_think(philosopher);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	philosopher->last_meal_time = ft_get_time();
	while (1)
	{
		safety_mutex(&philosopher->data->protect_mutex, LOCK);
		if (philosopher->data->is_finished || philosopher->is_full)
		{
			safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
			break ;
		}
		if (philosopher->data->meals_required != -1
			&& philosopher->meals_counter >= philosopher->data->meals_required)
		{
			philosopher->is_full = true;
			safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
			break ;
		}
		safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
		routine_from_philosophers(philosopher);
	}
	return (NULL);
}

void	philosopher_eat(t_philosopher *philosopher)
{
	t_fork	*first_fork;
	t_fork	*second_fork;

	if (philosopher->left_fork->id_fork < philosopher->right_fork->id_fork)
	{
		first_fork = philosopher->left_fork;
		second_fork = philosopher->right_fork;
	}
	else
	{
		first_fork = philosopher->right_fork;
		second_fork = philosopher->left_fork;
	}
	if (philosopher->data->meals_required > 0
		&& philosopher->meals_counter == philosopher->data->meals_required)
		philosopher->is_full = true;
	philo_is_eating(philosopher, first_fork, second_fork);
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	print_status(philosopher, BLUE "is sleeping   😴"RESET);
	usleep(philosopher->data->time_to_sleep);
}

void	philosopher_think(t_philosopher *philosopher)
{
	print_status(philosopher, GREEN"is thinking.  🤔"RESET);
}
