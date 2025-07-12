#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>
# include <errno.h>


# define RESET	"\033[0m"
# define RED	"\033[1;31m"
# define ROSE	"\033[38;5;200m"
# define PURPLE	"\033[1;36m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
#define YELLOW 	"\033[1;33m"
#define EMOJI_SKULL "💀"
#define EMOJI_FORK  "🍴"
#define EMOJI_EAT   "🍝"


typedef pthread_mutex_t t_mutex;
typedef struct s_data t_data;
typedef struct s_philosopher t_philosopher;

typedef enum safety 
{
    CREATE,
    JOIN,
    DESTROY,
    INIT,
    LOCK,
    UNLOCK,
    DETACH,
} t_safety;

typedef struct s_fork
{
    int		id_fork;
    t_mutex	fork;
}			t_fork;

typedef struct s_philosopher
{
	int			id;
	int			meals_counter;
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	philo_thread;
	bool		is_full;
	t_data		*data; // Pointer to shared data structure
}               t_philosopher;

typedef struct s_data
{
	long			nbr_philo; //av[1]
	long			time_to_die; //av[2]
	long			time_to_eat; //av[3]
	long			time_to_sleep;//av[4]
	long			meals_required; // ? av[5] : nothing
	long			start_time;
	bool			is_finished;
	t_mutex			protect_mutex;
	t_fork			*forks;
	t_philosopher	*philosophers;
}					t_data;


void	error_function(const char *message);
void	*check_malloc(size_t size);
void print_status(t_philosopher *philo, const char *message);
void	parsing(t_data *data, char **argv);
void		validate_time(int time, const char *message);
void	safety_mutex(t_mutex *mutex, t_safety action);
void	mutex_error(int action, t_safety safety);
void	safety_phread(pthread_t *thread,void *(*foo)(void *),void *data, t_safety action);
void	ft_initialisation(t_data *data);
void    executor(t_data *data);
void    *philosopher_routine(void *arg);
void    philosopher_eat(t_philosopher *philosopher);
void    philosopher_sleep(t_philosopher *philosopher);
void    philosopher_think(t_philosopher *philosopher);
long	ft_get_time(void);
void	ft_usleep(long time_in_ms);
void	ft_exit(t_data *data);
bool check_all_philos_full(t_data *data);
void philo_is_eating(t_philosopher *philosopher, t_fork *first_fork, t_fork *second_fork);

















# endif
