#ifndef TIMESTAMP_H
# define TIMESTAMP_H

# include <stdlib.h>
# include <sys/time.h>

typedef struct timeval	t_timeval;

size_t  get_ms_now(void);
size_t	get_timestamp(size_t ms_begin);

#endif