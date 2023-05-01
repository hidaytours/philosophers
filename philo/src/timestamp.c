#include "timestamp.h"

size_t	get_timestamp(size_t ms_begin)
{
	size_t		ms;
	t_timeval	timeval;

	gettimeofday(&timeval, NULL);
	ms = timeval.tv_sec * 1000 + timeval.tv_usec / 1000;
	return (ms - ms_begin);
}
