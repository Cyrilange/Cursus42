#include "philosophers.h"

void    error_function(const char *message)
{
    printf(RED"%s \n"RESET, message);
    exit(EXIT_FAILURE);
}

void check_malloc(size_t *memory)
{
    void *message;
    message = malloc(memory);
    if (!message)
        error_function("Error: Memory allocation failed.");
    return (message);
}

int validate_time(int time, const char *message)
{
    if (time <= 0)
        error_function(message);
    return 0;
}
