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
	return ptr;
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
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
