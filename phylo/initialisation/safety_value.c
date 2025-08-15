#include "../philosophers.h"

void no_repeat_mutexes(t_mutex *mutex, bool *dest, bool value) //setbool
{
    safety_mutex(mutex, LOCK);
    *dest = value;
    safety_mutex(mutex, UNLOCK);    
}

bool take_off_bool(t_mutex *mutex, bool *value) //getbool
{
    bool taken;

    safety_mutex(mutex, LOCK);
    *value = false;
    safety_mutex(mutex, UNLOCK);
    return (taken);
}

void set_value(t_mutex *mutex, long *value, bool new_value)
{
    safety_mutex(mutex, LOCK);
    *value = new_value;
    safety_mutex(mutex, UNLOCK);
}

long take_off_long(t_mutex *mutex, long *value)
{
    long taken;

    safety_mutex(mutex, LOCK);
    taken = *value;
    safety_mutex(mutex, UNLOCK);
    return (taken);
}

bool	validate_times_die(t_data *data)
{
	if (data->time_to_die <= data->time_to_eat + data->time_to_sleep)
		return (false);
	return (true);
}