#include "philo.h"

void	routine_philo(void *p)
{
	t_philo	*philo_p;

	philo_p = p;
	//thinking
	philo_p->is_eating = false;
	printf("Philo x is thinking\n");
	//pickrfork
	pthread_mutex_lock(philo_p->fork_r);
	//picklfork
	pthread_mutex_lock(philo_p->fork_l);
	philo_p->is_eating = true;
	printf("Philo x is eating\n");
	usleep((philo_p->dtable_p)->ms_to_eat);
	philo_p->times_ate++;
	philo_p->is_eating = false;
	pthread_mutex_unlock(philo_p->fork_l);
	pthread_mutex_unlock(philo_p->fork_r);
	printf("Philo x is sleeping\n");
	usleep((philo_p->dtable_p)->ms_to_sleep);
}

void	routine_monitor_life_death(void	*p)
{
	t_philo	*philo_p;

	philo_p = p;
	
}

static bool is_quota_achieved(t_philo **philos, size_t num_philos, size_t quota)
{
	size_t	i;

	i = 0;
	while (num_philos > i)
		if (philos[i++]->times_ate < quota)
			return (false);
	return (true);
}

void	routine_monitor_quota(void	*p)
{
	size_t			i;
	size_t			num_philos;
	size_t			quota;
	t_dining_table	*dtable_p;
	t_philo			**philos;

	dtable_p = p;
	num_philos = dtable_p->num_of_philos;
	quota = dtable_p->quota_of_times_to_eat;
	philos = dtable_p->philos;
	while (!dtable_p->should_end)
	{
		if(is_quota_achieved(philos, num_philos, quota))
			dtable_p->should_end = true;
	}
}
