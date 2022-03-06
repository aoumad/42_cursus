//
// Created by abder on 05/03/2022.
//

#include "push_swap.h"

void    reverse_rotate_a(t_array *stack_a, int type)
{
    int last_element; // same as rotate the last element will be lost
    if (type)
        ft_putendl_fd("rra", 1);
    else if (stack_a->used_size >= 3)
    {
        last_element = stack_a->array[stack_a->used_size - 1];
        clear_top(stack_a->array, stack_a->used_size);
        stack_a->array[0] = last_element;
    }
}

void    reverse_rotate_b(t_array *stack_b, int type)
{
    int last_element;
    if (type)
        ft_putendl_fd("rb", 1);
    else if (stack_b->used_size >= 3)
    {
        last_element = stack_b->array[stack_b->used_size - 1];
        clear_top(stack_b->array, stack_b->used_size);
        stack_b->array[0] = last_element;
    }
}

void    reverse_rotate_both(t_stacks *stacks, int type)
{
    if (type)
        ft_putendl_fd("rrr", 1);
    reverse_rotate_a(&stacks->stack_a, OFF);
    reverse_rotate_b(&stacks_stack_b, OFF);
}