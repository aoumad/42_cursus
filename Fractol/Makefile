# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 13:40:49 by aoumad            #+#    #+#              #
#    Updated: 2022/05/13 16:06:24 by aoumad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRCS	=	srcs/color.c srcs/fractol.c srcs/helpers.c srcs/inits.c \
			srcs/libft.c srcs/main.c srcs/input_check.c srcs/key_hooks.c
OBJS	= $(SRCS:.c=.o)
MAIN	= srcs/main.c

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LDFLAGS = -lmlx -framework OpenGL -framework AppKit

%.o : 		%.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

${NAME}:	${OBJS} includes/fractol.h
				@${CC} ${OBJS} $(LDFLAGS) -o ${NAME}
clean:
				@rm -f ${OBJS}
				
fclean:		clean
				@rm -f ${NAME}
				
re:			fclean all


