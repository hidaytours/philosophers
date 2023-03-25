NAME = philo
CC = cc
INCLUDES = -I ./include
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
DIR_SRC = ./src
SRCS =	$(DIR_SRC)/main.c	\
		$(DIR_SRC)/validation.c	\
		$(DIR_SRC)/convert.c

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
