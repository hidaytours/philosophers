#ifndef SIGNBOARD_H
# define SIGNBOARD_H

# include <stdbool.h>
# include <pthread.h>

typedef struct s_signboard {
	bool			is_closed;
	pthread_mutex_t	mutex;
}	t_signboard;

int		sb_init(t_signboard *p);
void	sb_fin(t_signboard *p);
bool	sb_is_closed(t_signboard *p);
void	sb_close(t_signboard *p);

#endif
