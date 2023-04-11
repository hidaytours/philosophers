#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>

# include "validation.h"
# include "convert.h"

typedef struct	s_dining_table
{
	size_t			num_of_philos;
	useconds_t		ms_to_die;
	useconds_t		ms_to_eat;
	useconds_t		ms_to_sleep;
	size_t			num_of_times_each_philos_must_eat;
	useconds_t		ms_begin;
	struct s_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	logging;
} t_dining_table;

typedef struct s_philo
{
	size_t			times_ate;
	useconds_t		ms_last_ate;
	pthread_mutex_t *fork_r;
	pthread_mutex_t *fork_l;
	pthread_t 		id;
	pthread_t		monitor_id;
}	t_philo;

#endif
