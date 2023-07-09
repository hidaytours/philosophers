# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toryoshi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 16:58:15 by toryoshi          #+#    #+#              #
#    Updated: 2023/07/06 16:58:19 by toryoshi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
INCLUDES = -I ./include
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) #-fsanitize=thread
DIR_SRC = ./src
SRCS =	$(DIR_SRC)/validation.c		\
		$(DIR_SRC)/signboard.c		\
		$(DIR_SRC)/timestamp.c		\
		$(DIR_SRC)/philo.c			\
		$(DIR_SRC)/chalk.c			\
		$(DIR_SRC)/log.c			\
		$(DIR_SRC)/input.c			\
		$(DIR_SRC)/routine_philo.c	\
		$(DIR_SRC)/routine_others.c	\
		$(DIR_SRC)/initialize.c		\
		$(DIR_SRC)/finalize.c		\
		$(DIR_SRC)/main.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -lpthread

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
