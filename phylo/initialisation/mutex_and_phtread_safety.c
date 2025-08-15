/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_and_phtread_safety.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-13 16:06:11 by csalamit          #+#    #+#             */
/*   Updated: 2025-07-13 16:06:11 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	mutex_error(int action, t_safety safety)
{
	if (action == 0)
		return ;
	else if (action == EINVAL && (safety == LOCK || safety == UNLOCK))
		error_function("Error:The value pass by mutex is not valid.");
	else if (action == EINVAL && safety == INIT)
		error_function("Error: The mutex is already initialized or destroyed.");
	else if (action == EDEADLK)
		error_function("Error: A deadlock condition was detected.");
	else if (action == EPERM)
		error_function("Error: The current thread does not own the mutex.");
	else if (action == EBUSY)
		error_function("Error: The mutex is already locked by another thread.");
	else if (action == ENOMEM)
		error_function("Error: Insufficient memory to create the mutex.");
}

void	safety_mutex(t_mutex *mutex, t_safety action)
{
	if (action == INIT)
		mutex_error(pthread_mutex_init(mutex, NULL), action);
	else if (action == LOCK)
		mutex_error(pthread_mutex_lock(mutex), action);
	else if (action == UNLOCK)
		mutex_error(pthread_mutex_unlock(mutex), action);
	else if (action == DESTROY)
		mutex_error(pthread_mutex_unlock(mutex), action);
	else
		error_function("Error: Invalid mutex action.");
}

void	safety_phread(pthread_t *thread, void *(*foo)(void *),
		void *data, t_safety action)
{
	if (action == CREATE)
		mutex_error(pthread_create(thread, NULL, foo, data), action);
	else if (action == JOIN)
		mutex_error(pthread_join(*thread, NULL), action);
	else if (action == DETACH)
		mutex_error(pthread_detach(*thread), action);
	else
		error_function("Error: Invalid <CREATE>, <JOIN>, <DETACH>.");
}
