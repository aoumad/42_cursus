/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 12:16:30 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	rotate_a(t_data *data)
{
	if (ra(data))
		write(1, "ra\n", 3);
}

void	rotate_b(t_data *data)
{
	if (rb(data))
		write(1, "rb\n", 3);
}

void	rev_rotate_a(t_data *data)
{
	if (rra(data))
		write(1, "rra\n", 4);
}

void	rev_rotate_b(t_data *data)
{
	if (rrb(data))
		write(1, "rrb\n", 4);
}

void	swap_b(t_data *data)
{
	if (sb(data))
		write(1, "sb\n", 3);
}
