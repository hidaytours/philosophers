#include "log.h"

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

static void	print_log(size_t timestamp, size_t num_philo, char *content)
{
	put_num(timestamp);
	put_str("	");
	put_num(num_philo);
	put_str(content);
}

void	take_log(t_philo *philo_p, char *content, pthread_mutex_t *chalk_p)
{
	size_t timestamp;

	pthread_mutex_lock(chalk_p);
	if (!philo_p->dtable_p->should_end)
	{
		timestamp = get_timestamp(philo_p->dtable_p->ms_begin);
		print_log(timestamp, philo_p->num, content);
	}
	pthread_mutex_unlock(chalk_p);
}
