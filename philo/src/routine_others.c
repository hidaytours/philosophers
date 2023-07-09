/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_others.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:51:18 by toryoshi          #+#    #+#             */
/*   Updated: 2023/07/06 16:51:21 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

void	*routine_alive(void	*p)
{
	t_philo			*philo_p;
	t_dining		*dining_p;
	size_t			elapsed;

	philo_p = p;
	dining_p = philo_p->dining_p;
	while (!sb_is_closed(&(dining_p->sb)))
	{
		pthread_mutex_lock(&(philo_p->mutex));
		elapsed = get_timestamp(dining_p->ms_begin) - philo_p->ms_last_ate;
		if (!philo_p->is_eating && elapsed > dining_p->ms_to_die)
			log_die(philo_p);
		pthread_mutex_unlock(&(philo_p->mutex));
		usleep(R_INTERVAL);
	}
	return (NULL);
}

static bool	is_quota_achieved(t_philo **philos, size_t num_philos, size_t quota)
{
	size_t	i;

	i = 0;
	while (num_philos > i)
	{
		if (!philos[i]->has_quota_achieved)
		{
			pthread_mutex_lock(&(philos[i]->mutex));
			if (philos[i]->times_ate < quota)
			{
				pthread_mutex_unlock(&(philos[i]->mutex));
				return (false);
			}
			philos[i]->has_quota_achieved = true;
			pthread_mutex_unlock(&(philos[i]->mutex));
		}
		i++;
	}
	return (true);
}

void	*routine_quota(void	*p)
{
	size_t			num_philos;
	size_t			quota;
	t_dining		*dining_p;
	t_philo			**philos;

	dining_p = p;
	num_philos = dining_p->num_of_philos;
	quota = dining_p->quota_of_times_to_eat;
	philos = dining_p->philos;
	while (!sb_is_closed(&(dining_p->sb)))
	{
		if (is_quota_achieved(philos, num_philos, quota))
		{
			sb_close(&(dining_p->sb));
			return (NULL);
		}
		usleep(R_INTERVAL);
	}
	return (NULL);
}
