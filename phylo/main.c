#include "philosophers.h"

int main(int argc, char **argv)
{
    t_data data;
    //int i;

    if (argc == 5 || argc == 6)
    {
        //i = -1;
        parsing(&data, argv);
        ft_initialisation(&data);
        executor(&data);
        ft_exit(&data);

       /* while (++i < data.nbr_philo)
            safety_mutex(&data.forks[i].fork, DESTROY);

        free(data.forks);
        free(data.philosophers); */
    }
    else
        error_function("Error: Invalid number of arguments. Usage: ./philosophers <nbr_philo> <time_to_die> <time_to_eat> <time_to_sleep> [meals_required]\n");   
    return 0;
}
