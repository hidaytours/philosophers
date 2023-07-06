/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:51:00 by toryoshi          #+#    #+#             */
/*   Updated: 2023/07/06 16:51:02 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	size_t			i;
	t_dining		dining;

	if (input_args(&dining, argc, argv))
		return (1);
	if (prepare_dining(&dining))
		return (1);
	i = 0;
	while (i < dining.num_of_philos)
	{
		pthread_join(dining.philos[i]->philo, NULL);
		pthread_join(dining.philos[i++]->alive, NULL);
	}
	if (dining.has_quota)
		pthread_join(dining.quota, NULL);
	clear_dining(0, dining.num_of_philos, dining.num_of_philos, &dining);
	return (0);
}
