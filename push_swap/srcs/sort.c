/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:41:24 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/21 00:56:47 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    largest_numbers(t_stacks *stacks, int *k, int *j, int *c)
{
    if (stacks->stack_a.array[*k] < stacks->stack_a.array[*j])
    {
        *k = *j;
        (*c)++;
    }
    if (*j == stacks->stack_a.size)
        *j = -1;
}

int get_index(int *t, int a, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (t[i] == a)
            return (i);
        i++;
    }
    return (-1);
}

void    sort_10(t_stacks *stacks)
{
    int index;
    int i;

    while (stacks->stack_b.used_size < (stacks->stack_b.size - 3))
    {
        i = 0;
        index = get_index(stacks->stack_a.array, get_min(stacks->stack_a.array,
            stacks->stack_a.used_size), stacks->stack_a.used_size);
        if (index <= stacks->stack_a.used_size / 2)
            while (i++ < index)
                ft_rotate_a(&stacks->stack_a, ON);
        else
            while (i++ < stacks->stack_a.used_size - index)
                reverse_rotate_a(&stacks->stack_a, ON);
        ft_pb(stacks, ON);
    }
    // printf("-----------------\n");
    // int j;
    // j = 0;
    // //printf("used size stak a %d\n",stacks->stack_a.used_size);
    
    // while (j < stacks->stack_a.used_size)
    // {
    //     printf("%d\n", stacks->stack_a.array[j]);
    //     j++;
    // }
    // printf("-------b---------\n");
    // j = 0;
    //   while (j < stacks->stack_b.used_size)
    // {
    //     printf("%d\n", stacks->stack_b.array[j]);
    //     j++;
    // }
    sort_3(stacks);
    while (stacks->stack_b.used_size)
        ft_pa(stacks, ON);
}

void    sort_3(t_stacks *stacks)
{
    int i;

    i = 0;
    while (!is_stack_a_sorted(stacks))
    {
      //  printf("the size is %d\n",stacks->stack_a.used_size);
        if (stacks->stack_a.array[0] > stacks->stack_a.array[1])
            ft_sa_or_sb(&stacks->stack_a, ON, 'a');
        if (is_stack_a_sorted(stacks))
            break;
            //int  j = 0;
    // while (j < stacks->stack_a.used_size)
    // {
    //     printf("%d\n", stacks->stack_a.array[j]);
    //     j++;
    // }
    // sleep(1);
        reverse_rotate_a(&stacks->stack_a, ON);
        
    }
}

/*int is_stack_a_sorted(t_stacks *stacks)
{
    int i;
    int res;

    res = 1;
    i = 0;
    while (res == 1 && i < stacks->stack_b.used_size - 1)
    {
        if (stacks->stack_a.array[i] > stacks->stack_a.array[i + 1])
            res = 0;
        i++;
    }
    if (res == 1)
        return (1);
    return (0);
}*/

int	is_stack_a_sorted(t_stacks *stacks)
{
	int	i;
	int	d;

	d = 1;
	i = 0;
	while (d == 1 && i < stacks->stack_a.used_size - 1)
	{
		if (stacks->stack_a.array[i] > stacks->stack_a.array[i + 1])
			d = 0;
		i++;
	}
	if (d == 1)
		return (1);
	return (0);
}