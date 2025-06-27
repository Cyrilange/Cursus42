#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>


# define RESET   "\033[0m"
# define RED     "\033[0;31m"
# define GREEN   "\033[0;32m"
# define BLUE    "\033[0;34m"

typedef pthread_mutex_t t_mutex;
typedef struct s_data t_data;
typedef struct s_philosopher t_philosopher;

typedef struct s_fork
{
    int             id_fork;
    t_mutex         fork;
}               t_fork;

typedef struct s_philosopher
{
    int             id;
    int             meals_counter;
    long            last_meal_time;
    t_fork         *left_fork;
    t_fork         *right_fork;
    pthread_t       philo_thread;
    bool            is_full;
    t_data         *data; // Pointer to shared data structure
}               t_philosopher;

typedef struct s_data
{
    int             nbr_philo; //av[1]
    int             time_to_die; //av[2]
    int             time_to_eat; //av[3]
    int             time_to_sleep;//av[4]
    int             meals_required; //av[5]
    long            start_time;
    t_fork          *forks;
    t_philosopher   *philosophers;
}               t_data;


void    error_function(const char *message);
void    check_malloc(size_t *memory);
void parsing(t_data *data, char **argv);
int validate_time(int time, const char *message);


















# endif
