#include "timestamp.h"

size_t	get_ms_now(void)
{
	t_timeval	timeval;

	gettimeofday(&timeval, NULL);
	return (timeval.tv_sec * 1000 + timeval.tv_usec / 1000);
}

size_t	get_timestamp(size_t ms_begin)
{
	return (get_ms_now() - ms_begin);
}
