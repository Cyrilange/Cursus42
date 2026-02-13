/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-13 15:42:17 by csalamit          #+#    #+#             */
/*   Updated: 2025-07-13 15:42:17 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>
# include <errno.h>

/* 🎨 Colors & Emojis */
# define RESET "\033[0m"
# define RED "\033[1;31m"
# define ROSE "\033[38;5;200m"
# define PURPLE "\033[1;36m"
# define GREEN "\033[1;32m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define EMOJI_SKULL "💀"
# define EMOJI_FORK "🍴"
# define EMOJI_EAT "🍝"

/* Typedefs & Enums */
typedef pthread_mutex_t   t_mutex;
typedef struct s_data     t_data;
typedef struct s_philosopher t_philosopher;

typedef enum	message {
	TAKEN_LEFT_FORK,
	TAKEN_RIGHT_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
}				t_message;

typedef enum	safety
{
	CREATE,
	JOIN,
	DESTROY,
	INIT,
	LOCK,
	UNLOCK,
	DETACH
}				t_safety;

typedef enum	e_unit
{
	MILLISECONDS,
	SECONDS,
	MICROSECONDS,
}				t_unit;

/* Structures */
typedef struct	s_fork
{
	int		id_fork;    // Fork's ID
	t_mutex	fork;       // Mutex for the fork
}				t_fork;

typedef struct	s_philosopher
{
	int			id;              // Philosopher's ID
	int			meals_counter;   // Number of meals eaten
	long		last_meal_time;  // Time of the last meal
	t_fork		*left_fork;      // Forks held by the philosopher
	t_fork		*right_fork;     // Forks held by the philosopher
	pthread_t	philo_thread;    // Thread for the philosopher
	bool		is_full;         // if the philosopher has eaten enough meals, Maximum number of meals to eat
	bool		is_eating;       // Indicates if the philosopher is currently eating
	bool		nbr_of_meals;    // numbers of meal philo must eat
	t_mutex		protect_mutex;   // Mutex to protect philosopher's data
	t_data		*data;           // Pointer to shared data structure
}				t_philosopher;

typedef struct	s_data {
	long			nbr_philo;           //av[1]
	long			time_to_die;         //av[2]
	long			time_to_eat;         //av[3]
	long			time_to_sleep;       //av[4]
	long			meals_required;      // ? av[5] : nothing
	long			nbr_of_meals;        // Number of meals each philosopher must eat
	long			start_time;          // Time when the simulation started
	long			philo_running;       // how many philo are running the routine simulation
	bool			is_ready;            // Indicates if the simulation is ready to start
	bool			is_finished;         // Indicates if the simulation is finished
	bool			someone_died;        // Indicates if a philosopher has died
	pthread_t		philo_death;         // Thread for monitoring philosophers death
	t_mutex			protect_data_races;  // Mutex to protect shared data
	t_mutex			protect_output;      // Mutex to protect output from multiple threads
	t_fork			*forks;              // Array of forks
	t_philosopher	*philosophers;     // Array of philosophers
}				t_data;


/* ---------------------- 🔴 Gestion des erreurs ---------------------- */
void	error_function(const char *message);
void	*check_malloc(size_t size);
void	mutex_error(int action, t_safety safety);
/* ---------------------- 📝 Parsing & Validation ---------------------- */
void	parsing(t_data *data, char **argv);
void	validate_time(int time, const char *message);
bool	validate_times_die(t_data *data);
/* ---------------------- 🔐 Mutex & Threads Safety ---------------------- */
void	safety_mutex(t_mutex *mutex, t_safety action);
void	safety_phread(pthread_t *thread, void *(*foo)(void *), void *data, t_safety action);
void	no_repeat_mutexes(t_mutex *mutex, bool *dest, bool value);
bool	take_off_bool(t_mutex *mutex, bool *value);
void	set_value(t_mutex *mutex, long *value, long new_value);
long	take_off_long(t_mutex *mutex, long *value);
/* ---------------------- ⚙️ Initialisation ---------------------- */
void	ft_initialisation(t_data *data);
/* ---------------------- 🍝 Philosopher Routine ---------------------- */
void	routine(t_data *data);
void	*philosopher_eat(void *arg);
void	philosopher_think(t_philosopher *philo, bool routine_think);
void	ft_alone(t_philosopher *philosopher);
/* ---------------------- ⏱️ Time Management ---------------------- */
long	ft_get_time(t_unit unit);
void	ft_usleep(t_data *data, long time_in_ms);
/* ---------------------- 📜 Status & Printing ---------------------- */
void	print_status(t_philosopher *philo, t_message message);
/* ---------------------- ☠️ Death Monitoring ---------------------- */
void	*monitor_death(void *arg);
int		philo_is_eating(t_philosopher *philosopher);
/* ---------------------- 🚪 Exit & Cleanup ---------------------- */
void	ft_exit(t_data *data);

#endif
