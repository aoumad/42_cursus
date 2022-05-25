# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 01:30:00 by aoumad            #+#    #+#              #
#    Updated: 2022/05/20 22:40:39 by aoumad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	=	srcs/big_sort.c srcs/calcul_utils.c srcs/check_errors.c \
			srcs/ft_split.c srcs/libft_utils_1.c srcs/main.c srcs/min_max.c \
			srcs/push_swap.c srcs/push.c srcs/reverse_rotate.c srcs/rotate.c \
			srcs/sort.c srcs/swap.c
			
OBJS	= $(SRCS:.c=.o)
MAIN	= srcs/main.c

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

%.o : 		%.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

${NAME}:	${OBJS} includes/push_swap.h
				@${CC} ${OBJS} -o ${NAME}
clean:
				@rm -f ${OBJS}
				
fclean:		clean
				@rm -f ${NAME}
				
re:			fclean all