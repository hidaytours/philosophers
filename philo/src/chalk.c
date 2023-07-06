/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chalk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:50:07 by toryoshi          #+#    #+#             */
/*   Updated: 2023/07/06 16:50:11 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chalk.h"

int	chalk_init(pthread_mutex_t *chalk_p)
{
	return (pthread_mutex_init(chalk_p, NULL));
}

void	chalk_fin(pthread_mutex_t *chalk_p)
{
	pthread_mutex_destroy(chalk_p);
}

static void	chalk_write(size_t timestamp, size_t num_philo, char *content)
{
	printf("%zu	%zu %s\n", timestamp, num_philo, content);
}

void	chalk_use(t_dining *p, size_t n, char *content)
{
	size_t			timestamp;
	pthread_mutex_t	*chalk_p;

	chalk_p = &(p->chalk);
	pthread_mutex_lock(chalk_p);
	if (!sb_is_closed(&(p->sb)))
	{
		timestamp = get_timestamp(p->ms_begin);
		chalk_write(timestamp, n, content);
	}
	pthread_mutex_unlock(chalk_p);
}

void	chalk_use_and_close(t_dining *p, size_t n, char *content)
{
	size_t			timestamp;
	pthread_mutex_t	*chalk_p;

	chalk_p = &(p->chalk);
	pthread_mutex_lock(chalk_p);
	if (!sb_is_closed(&(p->sb)))
	{
		sb_close(&(p->sb));
		timestamp = get_timestamp(p->ms_begin);
		chalk_write(timestamp, n, content);
	}
	pthread_mutex_unlock(chalk_p);
}
