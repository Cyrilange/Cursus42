#include "philosophers.h"

void    error_function(const char *message)
{
    printf(RED"%s \n"RESET, message);
    exit(EXIT_FAILURE);
}

void *check_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (!ptr)
        error_function("Error: Memory allocation failed.");
    return ptr;
}

int validate_time(int time, const char *message)
{
    if (time <= 0)
        error_function(message);
    return 0;
}
