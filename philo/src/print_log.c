#include "log.h"
/*
static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void	put_str(const char *s)
{
	size_t	len;

	len = ft_strlen(s);
	write(STDOUT_FILENO, s, len);
}

static void	put_num(size_t num)
{
	char	c;

	if (num >= 10)
	{
		put_num(num / 10);
		num %= 10;
	}
	c = '0' + num;
	write(STDOUT_FILENO, &c, 1);
}
*/

void	print_log(size_t timestamp, size_t num_philo, char *content)
{
	// put_num(timestamp);
	// put_str("	");
	// put_num(num_philo);
	// put_str(content);
	printf("%zu	%zu%s", timestamp, num_philo, content);
}
