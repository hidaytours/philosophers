/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chalk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:42:45 by toryoshi          #+#    #+#             */
/*   Updated: 2023/07/06 16:42:58 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHALK_H
# define CHALK_H

# include "philo.h"

# include <stdio.h>

# define LOG_TAKE_FORK	"has taken a fork"
# define LOG_EAT		"is eating"
# define LOG_SLEEP		"is sleeping"
# define LOG_THINK		"is thinking"
# define LOG_DIE		"died"

int		chalk_init(pthread_mutex_t *chalk_p);
void	chalk_fin(pthread_mutex_t *chalk_p);
void	chalk_use(t_dining *p, size_t n, char *content);
void	chalk_use_and_close(t_dining *p, size_t n, char *content);

#endif
