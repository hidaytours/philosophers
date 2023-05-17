#include "philo.h"

static void	print_philo_for_debug(t_dining_table *p)
{
	printf("num_of_philos				:	%zu\n", p->num_of_philos);
	printf("ms_to_die				:	%u\n", p->ms_to_die);
	printf("ms_to_eat				:	%u\n", p->ms_to_eat);
	printf("ms_to_sleep				:	%u\n", p->ms_to_sleep);
	if (p->has_quota)
		printf("quota_of_times_to_eat			:	%zu\n", p->quota_of_times_to_eat);
}

static bool init_philo(t_philo **p, size_t i, t_dining_table *d_p)
{
	*p = malloc(sizeof(t_philo));
	if (!*p)
		return (true);
	(*p)->times_ate = 0;
	(*p)->ms_last_ate = 0;
	(*p)->is_eating = false;
	(*p)->i = i;
	if ((*p)->i == 0)
		(*p)->fork_r = &(d_p->forks[d_p->num_of_philos - 1]);
	else
		(*p)->fork_r = &(d_p->forks[i - 1]);
	(*p)->fork_l = &(d_p->forks[i]);	
	(*p)->dtable_p = d_p;
	return (false);
}

static bool	initialize(t_dining_table *p)
{
	size_t	i;

	p->ms_begin = get_ms_now();
	//mutex chalkを作成
	if (pthread_mutex_init(&(p->chalk), NULL))
		return (true);
	//mutex forkを作成
	p->forks = malloc(sizeof(pthread_mutex_t) * p->num_of_philos);
	if (!p->forks)
		return (clear_table(0, 0, 0, p));
	i = 0;
	while (i < p->num_of_philos)
	{
		if (pthread_mutex_init(&(p->forks)[i], NULL))
			return (clear_table(0,0, i, p));
		i++;
	}
	//philosを作成
	p->philos = malloc(sizeof(t_philo *) * p->num_of_philos);
	if (!p->philos)
		return (clear_table(0, 0, p->num_of_philos, p));
	i = 0;
	while (i < p->num_of_philos)
	{
		if (init_philo(&(p->philos[i]), i, p))
			return (clear_table(0, i, p->num_of_philos, p));
		i++;
	}
	// threadを実行
	i = 0;
	while (i < p->num_of_philos)
	{
		if (pthread_create(&(p->philos[i]->id), NULL, routine_philo, p->philos[i]))
			return (clear_table(i, p->num_of_philos, p->num_of_philos, p));
		if (pthread_create(&(p->philos[i]->monitor_id), NULL, routine_monitor_life_death, p->philos[i]))
		{
			pthread_detach(p->philos[i]->id);
			return (clear_table(i, p->num_of_philos, p->num_of_philos, p));
		}
		i++;
	}
	return (false);
}

int	main(int argc, char **argv)
{
	size_t	i;
	t_dining_table	dtable;

	if (input_args(&dtable, argc, argv))
		return (1);
	print_philo_for_debug(&dtable);
	if (initialize(&dtable))
		return (1);
	i = 0;
	while (i < dtable.num_of_philos)
	{
		pthread_join(dtable.philos[i]->id, NULL);
		pthread_join(dtable.philos[i++]->monitor_id, NULL);
	}
	clear_table(0, dtable.num_of_philos, dtable.num_of_philos, &dtable);
	return (0);
}
