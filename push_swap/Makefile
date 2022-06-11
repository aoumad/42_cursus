# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#              #
#    Updated: 2022/06/11 12:16:22 by aoumad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = push_swap.c ft_check.c ft_tools.c push_a.c push_b.c swap.c rotate.c min_max.c ft_sort.c ft_calcul.c big_sort.c operation.c
OBJ= $(SRC:.c=.o)
SRC_BONUS = bonus/checker_bonus.c bonus/ft_check_bonus.c bonus/ft_fill_bonus.c bonus/ft_tools_bonus.c \
 bonus/push_a_bonus.c bonus/push_b_bonus.c bonus/swap_bonus.c bonus/rotate_bonus.c bonus/min_max_bonus.c \
 bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c
OBJ_BONUS= $(SRC_BONUS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm  -rf
NAME_BONUS = checker
NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c push_swap.h bonus/checker.h
	$(CC) $(FLAGS) -c $< -o $@

bonus : $(OBJ_BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re : fclean all

.PHONY: all clean fclean re