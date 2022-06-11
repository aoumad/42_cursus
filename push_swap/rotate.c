/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 12:16:54 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	ra(t_data *data)
{
	int	temp;
	int	i;

	i = 0;
	temp = data->stack_a[0];
	while (i < data->size_a)
	{
		data->stack_a[i] = data->stack_a[i + 1];
		i++;
	}	
	data->stack_a[data->size_a - 1] = temp;
	return (1);
}

int	rb(t_data *data)
{
	int	temp;
	int	i;

	i = 0;
	temp = data->stack_b[0];
	while (i < data->size_b)
	{
		data->stack_b[i] = data->stack_b[i + 1];
		i++;
	}	
	data->stack_b[data->size_b - 1] = temp;
	return (1);
}

int	rra(t_data *data)
{
	int	temp;
	int	i;

	i = data->size_a - 1;
	temp = data->stack_a[data->size_a - 1];
	while (i > 0)
	{
		data->stack_a[i] = data->stack_a[i - 1];
		i--;
	}	
	data->stack_a[0] = temp;
	return (1);
}

int	rrb(t_data *data)
{
	int	temp;
	int	i;

	i = data->size_b - 1;
	temp = data->stack_b[data->size_b - 1];
	while (i > 0)
	{
		data->stack_b[i] = data->stack_b[i - 1];
		i--;
	}	
	data->stack_b[0] = temp;
	return (1);
}

void	rotate_ab(t_data *data)
{
	ra(data);
	rb(data);
	write(1, "rr\n", 3);
}
