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

void	ft_usleep(t_data *data, long time_in_ms)
{
	long start = ft_get_time(MICROSECONDS);
	while ((ft_get_time(MICROSECONDS) - start) < time_in_ms)
	{
		if (data->is_finished) break;
		long now = ft_get_time(MICROSECONDS);
		long elapsed = now - start;
		long remaining = time_in_ms - elapsed;
		if (remaining > 10000)
			usleep(remaining / 2);
		else
			while (ft_get_time(MICROSECONDS) - start < time_in_ms) ;
	}
	
}