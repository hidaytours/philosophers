#include "convert.h"

bool	set_size_t_from_str(size_t *size_t_p, char *str)
{
	size_t	i;
	size_t	total;

	total = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (total > (SIZE_MAX - (str[i] - '0')) / 10)
			return (true);
		total = total * 10 + (str[i] - '0');
		i++;
	}
	*size_t_p = total;
	return (false);
}

bool	set_useconds_from_str(useconds_t *useconds_p, char *str)
{
	size_t		i;
	useconds_t	total;

	total = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (total > (UINT32_MAX - (str[i] - '0')) / 10)
			return (true);
		total = total * 10 + (str[i] - '0');
		i++;
	}
	*useconds_p = total;
	return (false);
}
