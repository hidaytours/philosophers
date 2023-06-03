#ifndef PHILO_H
# define PHILO_H

# include "signboard.h"
# include "timestamp.h"

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <pthread.h>

struct	s_philo;

typedef struct s_dining
{
	size_t			num_of_philos;
	useconds_t		ms_to_die;
	useconds_t		ms_to_eat;
	useconds_t		ms_to_sleep;
	bool			has_quota;
	size_t			quota_of_times_to_eat;
	size_t			ms_begin;
	struct s_philo	**philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	chalk;
	t_signboard		sb;
	pthread_t		quota;
}	t_dining;

typedef struct s_philo
{
	size_t			times_ate;
	size_t			ms_last_ate;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	bool			is_eating;
	bool			has_quota_achieved;
	size_t			i;
	pthread_t		philo;
	pthread_t		alive;
	t_dining		*dining_p;
}	t_philo;

bool	philo_init(t_philo **p, const size_t n, t_dining *d_p);
void	philo_fin(t_philo *p);
void	philo_before_eat(t_philo *p);
void	philo_after_eat(t_philo *p);

#endif
