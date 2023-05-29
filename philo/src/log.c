#include "log.h"

void	take_log(t_philo *philo_p, char *content)
{
	size_t timestamp;
	pthread_mutex_t	*chalk_p;

	chalk_p = &(philo_p->dtable_p->chalk);
	pthread_mutex_lock(chalk_p);
	if (!sb_is_closed(&(philo_p->dtable_p->sb)))
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
	if (!sb_is_closed(&(philo_p->dtable_p->sb)))
	{
		sb_close(&(philo_p->dtable_p->sb));
		timestamp = get_timestamp(philo_p->dtable_p->ms_begin);
		print_log(timestamp, philo_p->i + 1, LOG_DIE);
	}
	pthread_mutex_unlock(chalk_p);
}
