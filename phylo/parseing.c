/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-13 16:06:16 by csalamit          #+#    #+#             */
/*   Updated: 2025-07-13 16:06:16 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static char	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

static bool	is_valid_number(const char *str)
{
	if (*str == '\0')
		return (false);
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (false);
	while (*str)
	{
		if (!is_digit(*str))
			return (false);
		str++;
	}
	return (true);
}

static int	check_atoi(const char *str)
{
	long	result;

	result = 0;
	while (is_space(*str))
		str++;
	if (!is_valid_number(str))
		error_function("Error: Invalid number format.");
	while (is_digit(*str))
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
			error_function("Error: Number out of range.");
		result = result * 10 + (*str - '0');
		str++;
	}
	if (result > INT_MAX)
		error_function("Error: Number out of range.");
	return ((int)(result));
}

void	parsing(t_data *data, char **argv)
{
	data->nbr_philo = check_atoi(argv[1]);
	validate_time(data->nbr_philo, "Must have at least 1 philo");
	data->time_to_die = check_atoi(argv[2]);
	validate_time(data->time_to_die, "T to die not positive number");
	data->time_to_eat = check_atoi(argv[3]);
	validate_time(data->time_to_eat, "T to eat not positive number");
	data->time_to_sleep = check_atoi(argv[4]);
	validate_time(data->time_to_sleep, "T to sleep not positive number");
	if (argv[5])
	{
		data->meals_required = check_atoi(argv[5]);
		validate_time(data->meals_required, "Nbr of meals not positive number");
	}
	else
		data->meals_required = -1;
}
