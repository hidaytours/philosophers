#ifndef INPUT_H
# define INPUT_H

# include "validation.h"

# include <unistd.h>
# include <stdint.h>

typedef struct s_dining_table
{
	size_t			num_of_philos;
	useconds_t		ms_to_die;
	useconds_t		ms_to_eat;
	useconds_t		ms_to_sleep;
	bool			has_quota;
	size_t			quota_of_times_to_eat;
	useconds_t		ms_begin;
	struct s_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	logging;
}	t_dining_table;

typedef struct s_philo
{
	size_t			times_ate;
	useconds_t		ms_last_ate;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	pthread_t		id;
	pthread_t		monitor_id;
}	t_philo;

bool	input_args(t_dining_table *p, int argc, char **argv);

#endif
