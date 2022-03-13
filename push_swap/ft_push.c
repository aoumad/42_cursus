/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:01:09 by aoumad            #+#    #+#             */
/*   Updated: 2022/03/12 19:16:32 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_a(t_stacks *stacks, int type)
{
    int sizeof_a;
    int sizeof_b;
    int i;

    i = 0;
    sizeof_a = stacks->stack_a.used_size;
    sizeof_b = stacks->stack_b.used_size;
    if (sizeof_b == 0)
        return ;
    if (type)
        ft_putendl_fd("pa", 1);
    if (sizeof_a == 0)
        stacks->stack_a.array[0] = stacks->stack_b.array[0];
    else
    {
        clear_top(stacks->stack_a.array, stacks->stack_a.used_size);
        stacks->stack_a.array[0] = stacks->stack_b.array[0]; 
    }
    shift_to_top(stacks->stack_b.array, stacks->stack_b.used_size);
    stacks->stack_a.used_size++;
    stacks->stack_b.used_size--;
}

void    push_b(t_stacks *stacks, int type)
{
    int sizeof_a;
    int sizeof_b;
    int i;

    i = 0;
    sizeof_a = stacks->stack_a.used_size;
    sizeof_b = stacks->stack_b.used_size;
    if (sizeof_a == 0)
        return ;
    if (type)
        ft_putendl_fd("pb", 1);
    if (sizeof_b == 0)
        stacks->stack_b.array[0] = stacks->stack_a.array[0];
    else
    {
        clear_top(stacks->stack_b.array, stacks->stack_b.used_size);
        stacks->stack_b.array[0] = stacks->stack_a.array[0]; 
    }
    shift_to_top(stacks->stack_a.array, stacks->stack_a.used_size);
    stacks->stack_b.used_size++;
    stacks->stack_a.used_size--;
}