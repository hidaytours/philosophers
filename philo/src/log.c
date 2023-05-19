#include "log.h"

void	take_log(t_philo *philo_p, char *content)
{
	size_t timestamp;
	pthread_mutex_t	*chalk_p;

	chalk_p = &(philo_p->dtable_p->chalk);
	pthread_mutex_lock(chalk_p);
	if (!philo_p->dtable_p->should_end)
	{
		timestamp = get_timestamp(philo_p->dtable_p->ms_begin);
		print_log(timestamp, philo_p->i + 1, content);
	}
	pthread_mutex_unlock(chalk_p);
}

void	take_log_die(t_philo *philo_p)
{
	size_t			timestamp;
	pthread_mutex_t	*chalk_p;

	chalk_p = &(philo_p->dtable_p->chalk);
	pthread_mutex_lock(chalk_p);
	if (!philo_p->dtable_p->should_end)
	{
		philo_p->dtable_p->should_end = true;
		timestamp = get_timestamp(philo_p->dtable_p->ms_begin);
		print_log(timestamp, philo_p->i + 1, LOG_DIE);
	}
	pthread_mutex_unlock(chalk_p);
}
