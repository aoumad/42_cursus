/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 12:16:59 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	sb(t_data *data)
{
	int	k;

	if (data->size_b > 1)
	{
		k = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = k;
		return (1);
	}
	return (0);
}

int	sa(t_data *data)
{
	int	k;

	if (data->size_a > 1)
	{
		k = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = k;
		return (1);
	}
	return (0);
}

void	swap_a(t_data *data)
{
	if (sa(data))
		write(1, "sa\n", 3);
}

void	swap_ab(t_data *data)
{
	sa(data);
	sb(data);
	write(1, "ss\n", 3);
}

void	rev_rotate_a_b(t_data *data)
{
	rrb(data);
	rra(data);
	write(1, "rrr\n", 4);
}
