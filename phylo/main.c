#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		parsing(&data, argv);
		ft_initialisation(&data);
		executor(&data);
		ft_exit(&data);
	}
	else
	{
		error_function("Error: Invalid number of arguments\n");
		printf("Usage: ./philosophers <nbr_philo> <time_to_die> ");
		printf("<time_to_eat> <time_to_sleep> [meals_required]\n");
	}
	return (0);
}
