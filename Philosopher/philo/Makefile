# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 14:17:20 by aoumad            #+#    #+#              #
#    Updated: 2022/07/18 17:01:12 by aoumad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SRCS	=	srcs/parsing/parsing_root.c srcs/tools/ft_atoi.c srcs/tools/ft_error.c \
			srcs/tools/ft_putstr_fd.c srcs/philo.c srcs/tools/ft_calloc.c srcs/parsing/mutex_handling.c \
			srcs/parsing/init_philos.c srcs/tools/ft_gettimeofday.c srcs/operations/cases_root.c srcs/operations/eating_case.c \
			srcs/operations/fork_case.c srcs/operations/sleeping_case.c \
			srcs/tools/ft_cout.c srcs/operations/destroy_mutex.c
OBJS	= $(SRCS:.c=.o)
MAIN	= srcs/philo.c

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

%.o : 		%.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

${NAME}:	${OBJS} includes/philo.h
				@${CC} ${OBJS} -o ${NAME}
clean:
				@rm -f ${OBJS}
				
fclean:		clean
				@rm -f ${NAME}
				
re:			fclean all