/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:51:35 by toryoshi          #+#    #+#             */
/*   Updated: 2023/07/06 16:51:37 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timestamp.h"

size_t	get_ms_now(void)
{
	t_timeval	timeval;

	gettimeofday(&timeval, NULL);
	return (timeval.tv_sec * 1000 + timeval.tv_usec / 1000);
}

size_t	get_timestamp(size_t ms_begin)
{
	return (get_ms_now() - ms_begin);
}
