/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:01:10 by aoumad            #+#    #+#             */
/*   Updated: 2022/03/10 11:01:10 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int check_number(char *number)
{
    int i;

    i = 0;
    if (number[i] == '-')
        i++;
    while (number[i])
    {
        if (!ft_isdigit(number[i]))
            return (0);
        i++;
    }
    return (1);
}

int check_duplicates(t_stacks *stacks, int number)
{
    int size;
    int i;

    i = 0;
    size = stacks->stack_a.used_size;
    if (!size)
        return (1);
    while (i < size)
    {
        if (stacks->stack_a.array[i] == number)
            return (0);
        i++;
    }
    return (1);
}

int check_if_sorted(t_array *array)
{
    int i;
    int *temp;

    i = 0;
    temp = array->array;
    while (i < array->used_size - 1)
    {
        if (temp[i] > temp[i + 1])
            return (0);
        i++;
    }
    return (1);
}