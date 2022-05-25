/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:11:59 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/19 17:47:14 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void    reverse_rotate_a(t_array *stack_a, int type)
{
    int last_elm;

    if (type)
        write(1, "rra\n", 4);
    last_elm = stack_a->array[stack_a->used_size - 1];
    ft_clear_first_elm(stack_a->array, stack_a->used_size);
    stack_a->array[0] = last_elm;
}

void    reverse_rotate_b(t_array *stack_b, int type)
{
    int last_elm;

    if (type)
        write(1, "rrb\n", 4);
    last_elm = stack_b->array[stack_b->used_size - 1];
    ft_clear_first_elm(stack_b->array, stack_b->used_size);
    stack_b->array[0] = last_elm;
}

void	ft_rra_and_rrb(t_stacks *stacks, int type)
{
	if (type)
		write(1, "rrr\n", 4);
	reverse_rotate_a(&stacks->stack_a, OFF);
	reverse_rotate_b(&stacks->stack_b, OFF);
}
