#include "philosophers.h"

void philosopher_eat(t_philosopher *philosopher)
{
    t_fork *first_fork;
    t_fork *second_fork;

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

    pthread_mutex_lock(&first_fork->fork);
    print_status(philosopher, ROSE"has taken a fork"RESET);
    pthread_mutex_lock(&second_fork->fork);
    print_status(philosopher, PURPLE"has taken a fork"RESET);

    // Update last meal time, eat...
    safety_mutex(&philosopher->data->protect_mutex, LOCK);
    philosopher->last_meal_time = ft_get_time();
    safety_mutex(&philosopher->data->protect_mutex, UNLOCK);

    print_status(philosopher, YELLOW"is eating 🍽️"RESET);
    usleep(philosopher->data->time_to_eat);

    philosopher->meals_counter++;
    if (philosopher->data->meals_required != -1 && philosopher->meals_counter >= philosopher->data->meals_required)
        philosopher->is_full = true;

    pthread_mutex_unlock(&second_fork->fork);
    pthread_mutex_unlock(&first_fork->fork);
}


void philosopher_sleep(t_philosopher *philosopher)
{
    print_status(philosopher, BLUE "is sleeping  😴");
    usleep(philosopher->data->time_to_sleep);
}

void philosopher_think(t_philosopher *philosopher)
{
    print_status(philosopher,GREEN"is thinking.  🤔"RESET);
    usleep(1000); // Facultatif, ou ajuste pour ton projet
}
