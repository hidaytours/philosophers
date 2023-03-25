NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c
OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
