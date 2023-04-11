#include "philo.h"

static void	print_philo_for_debug(t_dining_table *p, int argc)
{
	printf("num_of_philos				:	%zu\n", p->num_of_philos);
	printf("ms_to_die				:	%u\n", p->ms_to_die);
	printf("ms_to_eat				:	%u\n", p->ms_to_eat);
	printf("ms_to_sleep				:	%u\n", p->ms_to_sleep);
	if (argc == 6)
		printf("num_of_times_each_philos_must_eat	:	%zu\n", p->num_of_times_each_philos_must_eat);
}

static bool	set_input(t_dining_table *p, int argc, char **argv)
{
	if (set_size_t_from_str(&p->num_of_philos, argv[1]))
		return (true);
	if (set_useconds_from_str(&p->ms_to_die, argv[2]))
		return (true);
	if (set_useconds_from_str(&p->ms_to_eat, argv[3]))
		return (true);
	if (set_useconds_from_str(&p->ms_to_sleep, argv[4]))
		return (true);
	if (argc == 6)
		if (set_size_t_from_str(&p->num_of_times_each_philos_must_eat, argv[5]))
			return (true);
	return (false);
}

int	main(int argc, char **argv)
{
	t_dining_table dtable;
	//struct timeval time;

	if (is_invalid_args(argc, argv))
		return (1);
	if (set_input(&dtable, argc, argv))
	{
		printf("Over flow!\n");
		return (1);
	}
	// philo.philos = malloc(sizeof(pthread_t) * philo.num_of_philos);
	// if (!philo.philos)
	// {
	// 	printf("allocation error.");
	// 	return (1);
	// }
	// gettimeofday(&time, NULL);
	// printf("%ld : %d\n", time.tv_sec, time.tv_usec);
	print_philo_for_debug(&dtable, argc);
	//free(philo.philos);
	return (0);
}
