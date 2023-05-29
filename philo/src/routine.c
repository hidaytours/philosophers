#include "philo.h"

void	*routine_philo(void *p)
{
	t_philo			*philo_p;
	t_dining_table	*dtable_p;

	philo_p = p;
	dtable_p = philo_p->dtable_p;
	while (!sb_is_closed(&(dtable_p->sb)))
	{
		take_log(philo_p, LOG_THINK);
		pthread_mutex_lock(philo_p->fork_r);
		pthread_mutex_lock(philo_p->fork_l);
		take_log(philo_p, LOG_TAKE_FORK);
		pthread_mutex_lock(&(philo_p->m_philo));
		philo_p->is_eating = true;
		philo_p->ms_last_ate = get_timestamp(philo_p->dtable_p->ms_begin);
		pthread_mutex_unlock(&(philo_p->m_philo));
		take_log(philo_p, LOG_EAT);
		usleep((philo_p->dtable_p)->ms_to_eat * 1000);
		pthread_mutex_lock(&(philo_p->m_philo));
		philo_p->times_ate++;
		philo_p->is_eating = false;
		pthread_mutex_unlock(&(philo_p->m_philo));
		pthread_mutex_unlock(philo_p->fork_l);
		pthread_mutex_unlock(philo_p->fork_r);
		take_log(philo_p, LOG_SLEEP);
		usleep((philo_p->dtable_p)->ms_to_sleep * 1000);
		usleep(10);
	}
	return (NULL);
}

void	*routine_monitor_life_death(void	*p)
{
	t_philo			*philo_p;
	t_dining_table	*dtable_p;
	size_t			elapsed;

	philo_p = p;
	dtable_p = philo_p->dtable_p;
	while (!sb_is_closed(&(dtable_p->sb)))
	{
		pthread_mutex_lock(&(philo_p->m_philo));
		elapsed = get_timestamp(dtable_p->ms_begin) - philo_p->ms_last_ate;
		if (!philo_p->is_eating && elapsed > dtable_p->ms_to_die)
			take_log_die(philo_p);
		pthread_mutex_unlock(&(philo_p->m_philo));
		usleep(10);
	}
	return (NULL);
}

static bool is_quota_achieved(t_philo **philos, size_t num_philos, size_t quota)
{
	size_t	i;

	i = 0;
	while (num_philos > i)
	{
		pthread_mutex_lock(&(philos[i]->m_philo));
		if (philos[i]->times_ate < quota)
		{
			pthread_mutex_unlock(&(philos[i]->m_philo));
			return (false);
		}
		pthread_mutex_unlock(&(philos[i]->m_philo));
		i++;
	}
	return (true);
}

void	*routine_monitor_quota(void	*p)
{
	size_t			num_philos;
	size_t			quota;
	t_dining_table	*dtable_p;
	t_philo			**philos;

	dtable_p = p;
	num_philos = dtable_p->num_of_philos;
	quota = dtable_p->quota_of_times_to_eat;
	philos = dtable_p->philos;
	while (!sb_is_closed(&(dtable_p->sb)))
	{
		if(is_quota_achieved(philos, num_philos, quota))
		{
			sb_close(&(dtable_p->sb));
			return (NULL);
		}
		usleep(1);
	}
	return (NULL);
}
