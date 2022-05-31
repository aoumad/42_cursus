# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 08:30:39 by aoumad            #+#    #+#              #
#    Updated: 2022/04/19 03:53:47 by aoumad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

SRCS	= srcs/pipex.c srcs/pipex_utils.c srcs/ft_split.c srcs/libft_utils.c
OBJS	= $(SRCS:.c=.o)
MAIN	= srcs/pipex.c

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

%.o : 		%.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

${NAME}:	${OBJS} includes/pipex.h
				@${CC} ${OBJS} -o ${NAME}
clean:
				@rm -f ${OBJS}
				
fclean:		clean
				@rm -f ${NAME}
				
re:			fclean all
