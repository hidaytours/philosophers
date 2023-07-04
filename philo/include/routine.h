#ifndef ROUTINE_H
# define ROUTINE_H

# include "philo.h"
# include "log.h"

# define R_INTERVAL 500

void	*routine_philo(void *p);
void	*routine_alive(void *p);
void	*routine_quota(void *p);

#endif
