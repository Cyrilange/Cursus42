/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-13 16:05:59 by csalamit          #+#    #+#             */
/*   Updated: 2025-07-13 16:05:59 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	error_function(const char *message)
{
	printf(RED"%s \n"RESET, message);
	exit(EXIT_FAILURE);
}

void	*check_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		error_function("Error: Memory allocation failed.");
	return (ptr);
}

void	validate_time(int time, const char *message)
{
	if (time <= 0)
		error_function(message);
}

long	ft_get_time(t_unit unit)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (unit == SECONDS)
		return (tv.tv_sec + (tv.tv_usec / 1000000));
	else if (unit == MILLISECONDS)
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	else if (unit == MICROSECONDS)
		return ( tv.tv_usec + (tv.tv_sec * 1000000));
	else
	{
		error_function("Error: Invalid time unit specified.");
		return (-1);
	}
	return (-1);
}
void	ft_usleep(t_data *data, long time_in_ms)
{
	long	start;
	long	now;
	long	current;

	start = ft_get_time(MICROSECONDS);
	while ((ft_get_time(MICROSECONDS) - start) < time_in_ms)
	{
		if (data->is_finished)
			break ;
		now = ft_get_time(MICROSECONDS);
		current = time_in_ms - now;
		if (current > 10000)
			usleep(current / 2);
		else
			while (ft_get_time(MICROSECONDS) - start < time_in_ms)
				;
	}
}