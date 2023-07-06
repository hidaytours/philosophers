/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:45:55 by toryoshi          #+#    #+#             */
/*   Updated: 2023/07/06 16:45:58 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include "chalk.h"

# define LOG_TAKE_FORK	"has taken a fork"
# define LOG_EAT		"is eating"
# define LOG_SLEEP		"is sleeping"
# define LOG_THINK		"is thinking"
# define LOG_DIE		"died"

void	log_think(t_philo *p);
void	log_take_fork(t_philo *p);
void	log_eat(t_philo *p);
void	log_sleep(t_philo *p);
void	log_die(t_philo *p);

#endif
