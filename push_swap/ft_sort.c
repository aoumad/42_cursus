/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 12:16:11 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	largest_numbers(t_data *data, int *k, int *j, int *c)
{
	if (data->stack_a[*k] < data->stack_a[*j])
	{
		*k = *j;
		(*c)++;
	}
	if (*j == data->size_a)
		*j = -1;
}

void	find_number_nosorted(t_data *data, int temp, int i, int j)
{
	if (data->t[j] == 0)
	{
		while (data->stack_a[0] != temp)
		{
			if (i >= (data->size_a / 2))
				rev_rotate_a(data);
			else
				rotate_a(data);
		}
		push_b(data);
	}
}

void	rotate(t_data *data, int tempb, int tempa, int j)
{
	int	min;

	min = get_index(data->p, get_min(data->p, data->size_b), data->size_b);
	while (tempa != data->stack_a[0])
	{	
		if (j >= data->size_a / 2)
			rev_rotate_a(data);
		else
			rotate_a(data);
	}
	while (tempb != data->stack_b[0])
	{
		if (min >= data->size_b / 2)
			rev_rotate_b(data);
		else
			rotate_b(data);
	}
}

void	sort_5(t_data *data)
{
	int	index;
	int	i;

	while (data->size_b < (data->max_size - 3))
	{
		i = 0;
		index = get_index(data->stack_a, get_min(data->stack_a, data->size_a),
				data->size_a);
		if (index <= data->size_a / 2)
			while (i++ < index)
				rotate_a(data);
		else
			while (i++ < data->size_a - index)
				rev_rotate_a(data);
		push_b(data);
	}
	sort_3(data);
	while (data->size_b)
		push_a(data);
}

void	sort_3(t_data *data)
{
	int	i;

	i = 0;
	while (!is_sorted_stacka(data))
	{
		if (data->stack_a[0] > data->stack_a[1])
			swap_a(data);
		if (is_sorted_stacka(data))
			break ;
		rev_rotate_a(data);
	}
}
