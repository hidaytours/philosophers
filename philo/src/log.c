/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:50:52 by toryoshi          #+#    #+#             */
/*   Updated: 2023/07/06 16:50:54 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

void	log_think(t_philo *p)
{
	chalk_use(p->dining_p, p->i + 1, LOG_THINK);
}

void	log_take_fork(t_philo *p)
{
	chalk_use(p->dining_p, p->i + 1, LOG_TAKE_FORK);
}

void	log_eat(t_philo *p)
{
	chalk_use(p->dining_p, p->i + 1, LOG_EAT);
}

void	log_sleep(t_philo *p)
{
	chalk_use(p->dining_p, p->i + 1, LOG_SLEEP);
}

void	log_die(t_philo *p)
{
	chalk_use_and_close(p->dining_p, p->i + 1, LOG_DIE);
}
