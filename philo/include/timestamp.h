/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:44:07 by toryoshi          #+#    #+#             */
/*   Updated: 2023/07/06 16:44:12 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMESTAMP_H
# define TIMESTAMP_H

# include <stdlib.h>
# include <sys/time.h>

typedef struct timeval	t_timeval;

size_t	get_ms_now(void);
size_t	get_timestamp(size_t ms_begin);

#endif
