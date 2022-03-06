//
// Created by abderazzak on 04/03/2022.
//

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typdef struct array
{
    int size;
    int used_size;
    int *array;
}               t_array;

typdef struct stack
{
    t_array stack_a;
    t_array stack_b;
}               t_stacks;
#endif //PUSH_SWAP_H

//libft functions
int     ft_isdigit(int c);
void	ft_putendl_fd(char *s, int fd);
char    *ft_strdup(const char *s);
size_t  ft_strlen(const char *s);
int     ft_strcmp(const char *s1, const char *s2);

//push_swap instructions
void ft_sa_or_sb(t_array *array, char stack, int type);
void    shift_to_top(int *array, int used_size);
void    clear_top(int *array, int used_size);
void ft_ss(t_stacks *stack, int type);

//check_errors functions
void    exit_error(void);