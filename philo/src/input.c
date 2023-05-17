#include "input.h"

static bool	overflow(char *name_arg, char *str)
{
	printf("Invalid number: %s: %s: Overflowed.\n", name_arg, str);
	return (true);
}

static bool	set_size_t_from_str(size_t *size_t_p, char *str, char *name_arg)
{
	size_t	i;
	size_t	total;

	total = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (total > (SIZE_MAX - (str[i] - '0')) / 10)
			return (overflow(name_arg, str));
		total = total * 10 + (str[i] - '0');
		i++;
	}
	*size_t_p = total;
	return (false);
}

static bool	set_usec_from_str(useconds_t *usec_p, char *str, char *name_arg)
{
	size_t		i;
	useconds_t	total;

	total = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (total > (UINT32_MAX - (str[i] - '0')) / 10)
			return (overflow(name_arg, str));
		total = total * 10 + (str[i] - '0');
		i++;
	}
	*usec_p = total;
	return (false);
}

bool	input_args(t_dining_table *p, int argc, char **argv)
{
	p->has_quota = false;
	p->should_end = false;
	p->forks = NULL;
	p->philos = NULL;
	if (is_invalid_args(argc, argv))
		return (true);
	if (set_size_t_from_str(&p->num_of_philos, argv[1], NAME_ARG1))
		return (true);
	if (set_usec_from_str(&p->ms_to_die, argv[2], NAME_ARG2))
		return (true);
	if (set_usec_from_str(&p->ms_to_eat, argv[3], NAME_ARG3))
		return (true);
	if (set_usec_from_str(&p->ms_to_sleep, argv[4], NAME_ARG4))
		return (true);
	if (argc == 6)
	{
		p->has_quota = true;
		if (set_size_t_from_str(&p->quota_of_times_to_eat, argv[5], NAME_ARG5))
			return (true);
	}
	return (false);
}
