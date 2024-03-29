/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signboard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:51:27 by toryoshi          #+#    #+#             */
/*   Updated: 2023/07/06 16:51:29 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signboard.h"

int	sb_init(t_signboard *p)
{
	p->is_closed = false;
	return (pthread_mutex_init(&(p->mutex), NULL));
}

void	sb_fin(t_signboard *p)
{
	pthread_mutex_destroy(&(p->mutex));
}

bool	sb_is_closed(t_signboard *p)
{
	bool	is_closed;

	pthread_mutex_lock(&(p->mutex));
	is_closed = p->is_closed;
	pthread_mutex_unlock(&(p->mutex));
	return (is_closed);
}

void	sb_close(t_signboard *p)
{
	pthread_mutex_lock(&(p->mutex));
	p->is_closed = true;
	pthread_mutex_unlock(&(p->mutex));
}
