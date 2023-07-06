/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:46:09 by toryoshi          #+#    #+#             */
/*   Updated: 2023/07/06 16:46:13 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include "philo.h"
# include "log.h"

# define R_INTERVAL 500

void	*routine_philo(void *p);
void	*routine_alive(void *p);
void	*routine_quota(void *p);

#endif
