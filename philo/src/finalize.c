#include "finalize.h"

bool	clear_table(size_t n_th, size_t n_ph, size_t n_f, t_dining_table *p)
{
	size_t	i;

	sb_close(&(p->sb));
	i = n_th;
	while (i > 0)
	{
		pthread_detach(p->philos[i - 1]->id);
		pthread_detach(p->philos[i-- - 1]->monitor_id);
	}
	i = n_ph;
	while (i > 0)
	{
		pthread_mutex_destroy(&((p->philos)[i - 1]->m_philo));
		free(p->philos[i-- - 1]);
	}
	if (p->philos)
		free(p->philos);
	i = n_f;
	while (i > 0)
		pthread_mutex_destroy(&(p->forks)[i-- - 1]);
	if (p->forks)
		free(p->forks);
	pthread_mutex_destroy(&(p->chalk));
	sb_fin(&(p->sb));
	return (true);
}
