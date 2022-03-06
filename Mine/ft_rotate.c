//
// Created by abder on 05/03/2022.
//

#include "push_swap.h"

void    rotate_a(t_array *stack_a, int type)
{
    int first_element; // because shift_to_top func will clear the first element
    int i;

    i = 1;
    if (type)
        ft_putendl_fd("ra", 1);
    else if (stack_a->used_size >= 3)
    {
        first_element = stack_a->array[0];
        shift_to_top(stack_a->array, stack_a->used_size);
        stack_a->array[stack_a->used_size - 1] = first_element;
    }
}

void    rotate_b(t_array *stack_b, int type) {
    int first_element;

    if (type)
        ft_putendl_fd("rb", 1);
    else if (stack_b->used_size >= 3)
    {
        first_element = stack_b->array[0];
        shift_to_top(stack_b->array,stack_b->used_size);
        stack_b->array[stack_b->used_size -1 ] = first_element;
    }
}

void  rotate_both(t_stacks *stacks, int type)
{
    if (type)
        ft_putendl_fd("rr", 1);
    rotate_a(&stacks->stack_a, OFF);
    rotate_b(&stacks->stack_b, OFF);
}