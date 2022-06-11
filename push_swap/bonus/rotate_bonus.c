/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 14:27:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_a(t_data *data)
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
}

void	rotate_b(t_data *data)
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
}

void	rev_rotate_a(t_data *data)
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
}

void	rev_rotate_b(t_data *data)
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
}

void	rotate_ab(t_data *data)
{
	rotate_a(data);
	rotate_b(data);
}
