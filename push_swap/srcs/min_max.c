/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:46:44 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/20 03:01:24 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

int get_max(int *t, int size)
{
    int max;
    int i;

    max = t[0];
    i = 1;
    while (i < size)
    {
        if (t[i] > max)
            max = t[i];
        i++;
    }
    return (max);
}

int get_min(int *t, int size)
{
    int min;
    int i;

    min = t[0];
    i = 1;
    while (i < size)
    {
        if (t[i] < min)
            min = t[i];
        i++;
    }
    return (min);
}

int small_max(t_stacks *stacks, int array_b)
{
    int i;
    int max;

    i = 0;
    max = get_max(stacks->stack_a.array, stacks->stack_a.size);
    while (i < stacks->stack_a.size)
    {
        if (stacks->stack_a.array[i] > array_b)
        {
            if (stacks->stack_a.array[i] < max)
                max = stacks->stack_a.array[i];
        }
        i++;
    }
    return(max);
}