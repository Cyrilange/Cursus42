#include "philosophers.h"


int main(int argc, char **argv)
{
    t_data data;

    if (argc == 5 || argc == 6)
    {
        parsing(&data, argv);
        //executor(&data);
        //cleanup(&data);

        printf("Parsed values:\n");
        printf("Philosophers: %d\n", data.nbr_philo);
        printf("Time to die: %d us\n", data.time_to_die);
        printf("Time to eat: %d us\n", data.time_to_eat);
        printf("Time to sleep: %d us\n", data.time_to_sleep);
        printf("Meals required: %d\n", data.meals_required);
    }
    else
        error_function("Error: Invalid number of arguments. Usage: ./philosophers <nbr_philo> <time_to_die> <time_to_eat> <time_to_sleep> [meals_required]\n");   
    return 0;
}