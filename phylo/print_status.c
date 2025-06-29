#include "philosophers.h"

void print_status(t_philosopher *philo, const char *message)
{
     // Acquire the protect_mutex before printing to prevent interleaved messages
    // and to ensure synchronized access to data->is_finished.
    safety_mutex(&philo->data->protect_mutex, LOCK);
    if (!philo->data->is_finished) // Only print if simulation is not finished
    {
        long timestamp = ft_get_time() - philo->data->start_time;
        printf("%ld philosopher %d %s\n", timestamp, philo->id, message);
    }
    safety_mutex(&philo->data->protect_mutex, UNLOCK);
}