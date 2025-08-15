/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-13 16:06:08 by csalamit          #+#    #+#             */
/*   Updated: 2025-07-13 16:06:08 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		parsing(&data, argv);
		ft_initialisation(&data);
		data.start_time = ft_get_time(MILLISECONDS);
		executor(&data);
		ft_exit(&data);
	}
	else
	{
		error_function("Error: Invalid number of arguments\n"
			"Usage: ./philosophers <number_of_philosophers> "
			"<time_to_die> <time_to_eat> <time_to_sleep> "
			"[number_of_meals_required]");
	}
	return (0);
}
