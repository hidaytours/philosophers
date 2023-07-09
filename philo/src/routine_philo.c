/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:51:18 by toryoshi          #+#    #+#             */
/*   Updated: 2023/07/06 16:51:21 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static bool	take_forks(t_philo	*p)
{
	pthread_mutex_lock(p->fork_r);
	log_take_fork(p);
	if (p->fork_l == p->fork_r)
	{
		pthread_mutex_unlock(p->fork_r);
		return (true);
	}
	pthread_mutex_lock(p->fork_l);
	log_take_fork(p);
	return (false);
}

static void	release_forks(t_philo *p)
{
	pthread_mutex_unlock(p->fork_l);
	pthread_mutex_unlock(p->fork_r);
}

static void	routine_eat(t_philo *p)
{
	philo_before_eat(p);
	log_eat(p);
	usleep((p->dining_p)->ms_to_eat * 1000);
	philo_after_eat(p);
	release_forks(p);
}

static void	routine_sleep(t_philo *p)
{
	log_sleep(p);
	usleep((p->dining_p)->ms_to_sleep * 1000);
}

void	*routine_philo(void *p)
{
	t_philo			*philo_p;
	t_dining		*dining_p;

	philo_p = p;
	dining_p = philo_p->dining_p;
	if (philo_p->i % 2)
		usleep(R_INTERVAL);
	while (!sb_is_closed(&(dining_p->sb)))
	{
		log_think(philo_p);
		if (take_forks(philo_p))
			return (NULL);
		if (sb_is_closed(&(dining_p->sb)))
		{
			release_forks(philo_p);
			return (NULL);
		}
		routine_eat(philo_p);
		if (sb_is_closed(&(dining_p->sb)))
			return (NULL);
		routine_sleep(philo_p);
		usleep(R_INTERVAL);
	}
	return (NULL);
}
