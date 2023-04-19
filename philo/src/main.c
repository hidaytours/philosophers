#include "philo.h"

static void	print_philo_for_debug(t_dining_table *p, int argc)
{
	printf("num_of_philos				:	%zu\n", p->num_of_philos);
	printf("ms_to_die				:	%u\n", p->ms_to_die);
	printf("ms_to_eat				:	%u\n", p->ms_to_eat);
	printf("ms_to_sleep				:	%u\n", p->ms_to_sleep);
	if (argc == 6)
		printf("num_of_times_must_eat			:	%zu\n", p->num_of_times_must_eat);
}

int	main(int argc, char **argv)
{
	t_dining_table	dtable;

	if (input_args(&dtable, argc, argv))
		return (1);
	print_philo_for_debug(&dtable, argc);
	return (0);
}
