#include "philo.h"

bool	philo_init(t_philo **p, const size_t n, t_dining *dining_p)
{
	*p = malloc(sizeof(t_philo));
	if (!*p)
		return (true);
	if (pthread_mutex_init(&((*p)->mutex), NULL))
	{
		free(*p);
		return (true);
	}
	(*p)->times_ate = 0;
	(*p)->ms_last_ate = 0;
	(*p)->is_eating = false;
	(*p)->has_quota_achieved = false;
	(*p)->i = n;
	if (n == 0)
	{
		(*p)->fork_l = &(dining_p->forks[dining_p->num_of_philos - 1]);
		(*p)->fork_r = &(dining_p->forks[0]);
	}
	else
	{
		(*p)->fork_r = &(dining_p->forks[n - 1]);
		(*p)->fork_l = &(dining_p->forks[n]);
	}
	(*p)->dining_p = dining_p;
	return (false);
}

void	philo_fin(t_philo *p)
{
	pthread_mutex_destroy(&(p->mutex));
	free(p);
}

void	philo_before_eat(t_philo *p)
{
	pthread_mutex_lock(&(p->mutex));
	p->is_eating = true;
	p->ms_last_ate = get_timestamp(p->dining_p->ms_begin);
	pthread_mutex_unlock(&(p->mutex));
}

void	philo_after_eat(t_philo *p)
{
	pthread_mutex_lock(&(p->mutex));
	p->times_ate++;
	p->is_eating = false;
	pthread_mutex_unlock(&(p->mutex));
}
