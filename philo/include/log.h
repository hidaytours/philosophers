#ifndef LOG_H
# define LOG_H

# include "input.h"
# include "timestamp.h"
# include <unistd.h>
# include <pthread.h>

# define LOG_TAKE_FORK	" has taken a fork\n"
# define LOG_EAT			" is eating\n"
# define LOG_SLEEP		" is sleeping\n"
# define LOG_THINK		" is thinking\n"
# define LOG_DIE			" died\n"

void	print_log(size_t timestamp, size_t num_philo, char *content);
void    take_log(t_philo *philo_p, char *content);
void    take_log_die(t_philo *philo_p);

#endif