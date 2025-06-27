#include "philosophers.h"


int main(int argc, char **argv)
{
    t_data data;

    if (argc == 5 || argc == 6)
    {
        parsing(&data, argv);
        init_forks(&data);
        init_philosophers(&data);
        start_philosophers(&data);
        cleanup(&data);
    }
    else
        error_function("Error: Invalid number of arguments. Usage: ./philosophers <nbr_philo> <time_to_die> <time_to_eat> <time_to_sleep> [meals_required]\n");   
    return 0;
}