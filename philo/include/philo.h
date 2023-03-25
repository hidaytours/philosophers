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

typedef struct	s_philo
{
	size_t		num_of_philos;
	useconds_t	ms_to_die;
	useconds_t	ms_to_eat;
	useconds_t	ms_to_sleep;
	size_t		num_of_times_each_philos_must_eat;
}	t_philo;

#endif
