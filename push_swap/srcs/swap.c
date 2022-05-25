/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:11:59 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/19 17:22:50 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void    ft_sa_or_sb(t_array *array, int type, char stack)
{
    int tmp;

    if (type && stack == 'a')
        write(1, "sa\n", 3);
    else if (type && stack == 'b')
        write(1, "sb\n", 3);
    if (array->used_size > 1)
    {
        tmp = array->array[0];
        array->array[0] = array->array[1];
        array->array[1] = tmp;
    }
}

void    ft_sa_and_sb(t_stacks *stacks, int type)
{
    if (type)
        write (1, "ss\n", 3);
    ft_sa_or_sb(&stacks->stack_a, OFF, 'a');
    ft_sa_or_sb(&stacks->stack_b, OFF, 'b');
}