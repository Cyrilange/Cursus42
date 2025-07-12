#include "philosophers.h"

static bool is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static char is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

static bool is_valid_number(const char *str)
{
	if (*str == '\0')
		return false;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return false;
	while (*str)
	{
		if (!is_digit(*str))
			return false;
		str++;
	}
	return true;
}

static int check_atoi(const char *str)
{
	long result;
	
	result = 0;
	while (is_space(*str))
		str++; // Skip leading whitespace
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
	return (int)(result);
}

void parsing(t_data *data, char **argv)
{
	data->nbr_philo = check_atoi(argv[1]);
	validate_time(data->nbr_philo,"Error: Must have at least 1 philosopher.");
	data->time_to_die = check_atoi(argv[2]) * 1000;
	validate_time(data->time_to_die,"Error: Time to die must be a positive number.");
	data->time_to_eat = check_atoi(argv[3]) * 1000;
	validate_time(data->time_to_eat,"Error: Time to eat must be a positive number.");
	data->time_to_sleep = check_atoi(argv[4]) * 1000;
	validate_time(data->time_to_sleep,"Error: Time to sleep must be a positive number.");
	if (argv[5])
	{
		data->meals_required = check_atoi(argv[5]);
		validate_time(data->meals_required, "Error: Number of meals must be a positive number.");
	}
	else
		data->meals_required = -1;
}