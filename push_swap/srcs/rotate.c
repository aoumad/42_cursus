/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:11:59 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/20 01:06:12 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void    ft_rotate_a(t_array *stack_a, int type)
{
    int first_elm;
    
    if (type)
        write(1, "ra\n", 3);
    first_elm = stack_a->array[0];
    ft_remove_first_elm(stack_a->array, stack_a->used_size);
    stack_a->array[stack_a->used_size - 1] = first_elm;
}

/*void	ft_rotate_a(t_array *stack_a, int type)
{
	int	temp;
	int	i;

	i = 0;
    if (type)
    write(1, "ra\n", 3);
	temp = stack_a->array[0];
	while (i < stack_a->size)
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}	
	stack_a->array[stack_a->size - 1] = temp;
}*/

/*void	ft_rotate_b(t_array *stack_b, int type)
{
	int	temp;
	int	i;

	i = 0;
    if (type)
    write(1, "rb/n", 3);
	temp = stack_b->array[0];
	while (i < stack_b->size)
	{
		stack_b->array[i] = stack_b->array[i + 1];
		i++;
	}	
	stack_b->array[stack_b->size - 1] = temp;
}*/

void    ft_rotate_b(t_array *stack_b, int type)
{
    int first_elm;

    if (type)
        write(1, "rb/n", 3);
    first_elm = stack_b->array[0];
    ft_remove_first_elm(stack_b->array, stack_b->used_size);
    stack_b->array[stack_b->used_size - 1] = first_elm;
}

void    ft_ra_and_rb(t_stacks *stacks, int type)
{
    if (type)
        write(1, "rr\n", 3);
    ft_rotate_a(&stacks->stack_a, OFF);
    ft_rotate_b(&stacks->stack_a, OFF);
}