#ifndef LOG_H
# define LOG_H

# include "input.h"
# include "timestamp.h"
# include <unistd.h>
# include <pthread.h>

# define LOG_TAKE_FORK	" has taken a fork\n"
# define LOG_EAT			" is eating\n"
# define LOG_SLEEP		" is sleeping\n"
# define LOG_THINK		" is thinking\n"
# define LOG_DIE			" died\n"

#endif