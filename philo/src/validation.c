/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:51:45 by toryoshi          #+#    #+#             */
/*   Updated: 2023/07/06 16:51:48 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static void	print_usage(void)
{
	printf("Usage: ./philo %s %s ", NAME_ARG1, NAME_ARG2);
	printf("%s %s [%s]\n", NAME_ARG3, NAME_ARG4, NAME_ARG5);
}

static bool	is_invalid_num_of_args(int argc)
{
	if (argc != 5 && argc != 6)
	{
		print_usage();
		return (true);
	}
	return (false);
}

static bool	is_only_num_char(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

static bool	format_err(char *name_arg, char *arg, bool has_invalid)
{
	if (!has_invalid)
		print_usage();
	printf("Invalid format:	%s:	%s:	Enter unsigned number.\n", name_arg, arg);
	return (true);
}

bool	is_invalid_args(int argc, char **argv)
{
	bool	is_invalid_format;

	if (is_invalid_num_of_args(argc))
		return (true);
	is_invalid_format = false;
	if (!is_only_num_char(argv[1]))
		is_invalid_format = format_err(NAME_ARG1, argv[1], is_invalid_format);
	if (!is_only_num_char(argv[2]))
		is_invalid_format = format_err(NAME_ARG2, argv[2], is_invalid_format);
	if (!is_only_num_char(argv[3]))
		is_invalid_format = format_err(NAME_ARG3, argv[3], is_invalid_format);
	if (!is_only_num_char(argv[4]))
		is_invalid_format = format_err(NAME_ARG4, argv[4], is_invalid_format);
	if (argc == 6 && !is_only_num_char(argv[5]))
		is_invalid_format = format_err(NAME_ARG5, argv[5], is_invalid_format);
	return (is_invalid_format);
}
