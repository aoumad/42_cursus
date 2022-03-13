//
// Created by abder on 04/03/2022.
//

#include "push_swap.h"

void ft_sa_or_sb(t_array *array, char stack, int type)
{
    int temp;

    if (type && stack == 'a')
        ft_putendl_fd("sa", 1);
    if (type && stack == 'b')
        ft_putendl_fd("sb", 1);
    else if (array->used_size > 1)
    {
        temp = array->array[0];
        array->array[0] = array->array[1];
        array->array[1] = temp;
    }
}

void ft_ss(t_stacks *stack, int type)
{
    if (type)
        ft_putendl_fd("ss", 1);
    ft_sa_or_sb(&stack->stack_a, 'a', OFF);
    ft_sa_or_sb(&stack->stack_b, 'b', OFF);
}