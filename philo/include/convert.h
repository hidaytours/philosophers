#ifndef CONVERT_H
# define CONVERT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

bool	set_size_t_from_str(size_t *size_t_p, char *str);
bool	set_useconds_from_str(useconds_t *useconds_p, char *str);

#endif