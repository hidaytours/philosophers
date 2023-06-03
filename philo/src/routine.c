#include "routine.h"

void	*routine_philo_one(void *p)
{
	t_philo			*philo_p;

	philo_p = p;
	log_think(philo_p);
	return (NULL);
}

void	*routine_philo(void *p)
{
	t_philo			*philo_p;
	t_dining		*dining_p;

	philo_p = p;
	dining_p = philo_p->dining_p;
	while (!sb_is_closed(&(dining_p->sb)))
	{
		log_think(philo_p);
		pthread_mutex_lock(philo_p->fork_r);
		pthread_mutex_lock(philo_p->fork_l);
		log_take_fork(philo_p);
		philo_before_eat(philo_p);
		log_eat(philo_p);
		usleep((philo_p->dining_p)->ms_to_eat * 1000);
		philo_after_eat(philo_p);
		pthread_mutex_unlock(philo_p->fork_l);
		pthread_mutex_unlock(philo_p->fork_r);
		log_sleep(philo_p);
		usleep((philo_p->dining_p)->ms_to_sleep * 1000);
		usleep(10);
	}
	return (NULL);
}

void	*routine_alive(void	*p)
{
	t_philo			*philo_p;
	t_dining		*dining_p;
	size_t			elapsed;

	philo_p = p;
	dining_p = philo_p->dining_p;
	while (!sb_is_closed(&(dining_p->sb)))
	{
		pthread_mutex_lock(&(philo_p->mutex));
		elapsed = get_timestamp(dining_p->ms_begin) - philo_p->ms_last_ate;
		if (!philo_p->is_eating && elapsed > dining_p->ms_to_die)
			log_die(philo_p);
		pthread_mutex_unlock(&(philo_p->mutex));
		usleep(10);
	}
	return (NULL);
}

static bool	is_quota_achieved(t_philo **philos, size_t num_philos, size_t quota)
{
	size_t	i;

	i = 0;
	while (num_philos > i)
	{
		if (!philos[i]->has_quota_achieved)
		{
			pthread_mutex_lock(&(philos[i]->mutex));
			if (philos[i]->times_ate < quota)
			{
				pthread_mutex_unlock(&(philos[i]->mutex));
				return (false);
			}
			philos[i]->has_quota_achieved = true;
			pthread_mutex_unlock(&(philos[i]->mutex));
		}
		i++;
	}
	return (true);
}

void	*routine_quota(void	*p)
{
	size_t			num_philos;
	size_t			quota;
	t_dining		*dining_p;
	t_philo			**philos;

	dining_p = p;
	num_philos = dining_p->num_of_philos;
	quota = dining_p->quota_of_times_to_eat;
	philos = dining_p->philos;
	while (!sb_is_closed(&(dining_p->sb)))
	{
		if (is_quota_achieved(philos, num_philos, quota))
		{
			sb_close(&(dining_p->sb));
			return (NULL);
		}
		usleep(1);
	}
	return (NULL);
}
