#include "philosophers.h"

static void print_status(t_philosopher *philo, const char *message)
{
    long timestamp = ft_get_time() - philo->data->start_time;
    printf("%ld philosopher %d %s\n", timestamp, philo->id, message);
}

void philosopher_eat(t_philosopher *philo)
{
    if (philo->id % 2 == 0)
    {
        safety_mutex(&philo->right_fork->fork, LOCK);
        print_status(philo, ROSE "has taken the right fork"RESET);
        safety_mutex(&philo->left_fork->fork, LOCK);
        print_status(philo, PURPLE "has taken the left fork"RESET);
    }
    else
    {
        safety_mutex(&philo->left_fork->fork, LOCK);
        print_status(philo, PURPLE "has taken the left fork"RESET);
      
        safety_mutex(&philo->right_fork->fork, LOCK);
        print_status(philo, ROSE "has taken the right fork"RESET);
     
    }
    print_status(philo, YELLOW"is eating  🍽️"RESET);
    philo->last_meal_time = ft_get_time();
    philo->meals_counter++;
    usleep(philo->data->time_to_eat * 1000);
    safety_mutex(&philo->left_fork->fork, UNLOCK);
    safety_mutex(&philo->right_fork->fork, UNLOCK);
}


void philosopher_sleep(t_philosopher *philosopher)
{
    print_status(philosopher, BLUE "is sleeping  😴");
    usleep(philosopher->data->time_to_sleep * 1000);
}

void philosopher_think(t_philosopher *philosopher)
{
    print_status(philosopher,GREEN"is thinking.  🤔"RESET);
    usleep(1000); // Facultatif, ou ajuste pour ton projet
}
