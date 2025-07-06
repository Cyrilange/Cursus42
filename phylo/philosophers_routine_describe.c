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
    if (philosopher->data->meals_required > 0
        && philosopher->meals_counter == philosopher->data->meals_required)
    {
        philosopher->is_full = true;
    }

    safety_mutex(&first_fork->fork, LOCK);
    print_status(philosopher, ROSE"has taken a fork"RESET);
    safety_mutex(&second_fork->fork, LOCK);
    print_status(philosopher, PURPLE"has taken a fork"RESET);
    
    // Update last meal time, eat...
    safety_mutex(&philosopher->data->protect_mutex, LOCK);
    philosopher->last_meal_time = ft_get_time();
    safety_mutex(&philosopher->data->protect_mutex, UNLOCK);
    
    philosopher->meals_counter++;
    print_status(philosopher, YELLOW"is eating 🍽️"RESET);
    usleep(philosopher->data->time_to_eat);

   

    safety_mutex(&second_fork->fork, UNLOCK);
    safety_mutex(&first_fork->fork, UNLOCK);
}


void philosopher_sleep(t_philosopher *philosopher)
{
    
    print_status(philosopher, BLUE "is sleeping  😴"RESET);
    usleep(philosopher->data->time_to_sleep);
}

void philosopher_think(t_philosopher *philosopher)
{
    print_status(philosopher,GREEN"is thinking.  🤔"RESET);
    usleep(1000); // Facultatif, ou ajuste pour ton projet
}
