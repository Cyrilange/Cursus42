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

#include "philosophers.h"

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

long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (tv.tv_sec < 0 || tv.tv_usec < 0)
		return (-1);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL));
}
