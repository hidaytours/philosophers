/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:43:20 by toryoshi          #+#    #+#             */
/*   Updated: 2023/07/06 16:43:26 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "validation.h"
# include "signboard.h"
# include "philo.h"

# include <stdio.h>
# include <stdint.h>

bool	input_args(t_dining *p, int argc, char **argv);

#endif
