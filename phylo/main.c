#include "philosophers.h"


int main(int argc, char **argv)
{
    t_data data;

    if (argc == 5 || argc == 6)
    {
        parsing(&data, argv);
        ft_initialisation(&data);
        executor(&data);
        free(data.forks);
        free(data.philosophers);
        safety_mutex(&data.protect_mutex, DESTROY);
    }
    else
        error_function("Error: Invalid number of arguments. Usage: ./philosophers <nbr_philo> <time_to_die> <time_to_eat> <time_to_sleep> [meals_required]\n");   
    return 0;
}