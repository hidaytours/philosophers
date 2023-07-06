/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:46:21 by toryoshi          #+#    #+#             */
/*   Updated: 2023/07/06 16:46:26 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# define NAME_ARG1 "number_of_philosophers"
# define NAME_ARG2 "time_to_die"
# define NAME_ARG3 "time_to_eat"
# define NAME_ARG4 "time_to_sleep"
# define NAME_ARG5 "number_of_times_each_philosopher_must_eat"

bool	is_invalid_args(int argc, char **argv);

#endif
