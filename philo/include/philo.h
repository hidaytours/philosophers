#ifndef PHILO_H
# define PHILO_H

# include "input.h"
# include "log.h"
# include "finalize.h"

# include <string.h>

void	*routine_philo(void *p);
void	*routine_monitor_life_death(void	*p);
void	*routine_monitor_quota(void	*p);

#endif
