#include "initialize.h"

static bool	prepare_forks(t_dining *p)
{
	size_t	i;

	p->forks = malloc(sizeof(pthread_mutex_t) * p->num_of_philos);
	if (!p->forks)
		return (clear_dining(0, 0, 0, p));
	i = 0;
	while (i < p->num_of_philos)
	{
		if (pthread_mutex_init(&(p->forks)[i], NULL))
			return (clear_dining(0, 0, i, p));
		i++;
	}
	return (false);
}

static bool	prepare_philos(t_dining *p)
{
	size_t	i;

	p->philos = malloc(sizeof(t_philo *) * p->num_of_philos);
	if (!p->philos)
		return (clear_dining(0, 0, p->num_of_philos, p));
	i = 0;
	while (i < p->num_of_philos)
	{
		if (ph_init(&(p->philos[i]), i, p))
			return (clear_dining(0, i, p->num_of_philos, p));
		i++;
	}
	return (false);
}

static bool	prepare_threads_philo(size_t i, size_t num, t_philo *p)
{
	if (pthread_create(&(p->philo), NULL, routine_philo, p))
		return (clear_dining(i, num, num, p->dining_p));
	if (pthread_create(&(p->alive), NULL, routine_alive, p))
	{
		pthread_detach(p->philo);
		return (clear_dining(i, num, num, p->dining_p));
	}
	return (false);
}

static bool	prepare_threads(t_dining *p)
{
	size_t	i;
	size_t	num;

	num = p->num_of_philos;
	i = 0;
	while (i < num)
	{
		if (prepare_threads_philo(i, num, p->philos[i]))
			return (true);
		i++;
	}
	if (p->has_quota)
		if (pthread_create(&(p->quota), NULL, routine_quota, p))
			clear_dining(num, num, num, p);
	return (false);
}

bool	prepare_dining(t_dining *p)
{
	p->ms_begin = get_ms_now();
	if (chalk_init(&(p->chalk)))
		return (true);
	if (sb_init(&(p->sb)))
	{
		chalk_fin(&(p->chalk));
		return (true);
	}
	if (prepare_forks(p))
		return (true);
	if (prepare_philos(p))
		return (true);
	if (prepare_threads(p))
		return (true);
	return (false);
}
