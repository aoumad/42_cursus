/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:00:39 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/21 01:00:51 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



void    calcul(t_stacks *stacks)
{
    int i;
    int j;
    int c;

    stacks->stack_b.t = (int *)malloc(sizeof(int) * stacks->stack_b.used_size);
    if (!stacks->stack_b.t)
        exit(ft_err_and_free(stacks, "Error", 1));
    i = 0;
    j = 0;
    while (i < stacks->stack_b.size)
    {
        c = 1;
        j = get_index(stacks->stack_a.array, small_max(stacks,
            stacks->stack_b.array[i]), stacks->stack_a.used_size);
       // printf("j is: %d\n", j);
        if (i >= stacks->stack_b.used_size / 2)
            c = c + (stacks->stack_b.used_size - i);
        else
            c = c + i;
        if (j >= stacks->stack_b.used_size / 2)
            c = c + (stacks->stack_a.used_size - j);
        else
            c = c + j;
        calcul_rr_rrr(stacks, i, &c, j);
        stacks->stack_b.t[i] = c;
        i++;
    }
    // i = 0;
    // while(i < stacks->stack_b.used_size)
    // {
    //     printf("%d-->%d\n",stacks->stack_b.array[i], stacks->stack_b.t[i]);
    //     i++;
    // }
    // printfstacks(stacks);
    // sleep(2);
}

void	calcul_rr_rrr(t_stacks *stacks, int i, int *c, int j)
{
    int s;
    
    if (i >= stacks->stack_b.used_size / 2 && j >= stacks->stack_a.used_size / 2)
    {
        if ((stacks->stack_b.used_size - i) < (stacks->stack_a.used_size - j))
            s = (stacks->stack_b.used_size - i);
        else if ((stacks->stack_b.used_size - i) > (stacks->stack_a.used_size - j))
            s = (stacks->stack_a.used_size - j);
        else
            s = (stacks->stack_b.used_size - i);
        *c = *c - s;
    }
    else if (i <= stacks->stack_b.used_size / 2 && j <= stacks->stack_a.used_size / 2)
    {
        if (i < j)
            s = i;
        else if (i > j)
            s = j;
        else
            s = j;
        *c = *c - s;
    }
}