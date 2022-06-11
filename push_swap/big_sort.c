/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 12:15:57 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	numbers_sorted(t_data *data)
{
	int	i;
	int	j;
	int	k;
	int	r;
	int	c;

	i = -1;
	r = -1;
	c = 1;
	data->t = (int *)malloc(sizeof(int) * data->size_a);
	if (!data->t)
		end(data);
	while (++i < data->size_a)
	{
		j = i + 1;
		k = i;
		while (++r < data->size_a)
		{
			largest_numbers(data, &k, &j, &c);
			j++;
		}
		data->t[i] = c;
		c = 1;
		r = -1;
	}
}

void	get_numbers_sorted(t_data *data)
{
	int	head;
	int	r;
	int	k;
	int	i;
	int	j;

	head = get_index(data->t, get_max(data->t, data->size_a),
			data->size_a);
	r = -1;
	k = head;
	i = 0;
	while (i < data->size_a)
		data->t[i++] = 0;
	j = k;
	data->t[k] = 1;
	while (++r < data->size_a - 1)
	{
		if (data->stack_a[k] < data->stack_a[++j])
		{
			k = j;
			data->t[k] = 1;
		}
		if (j == data->size_a - 1)
			j = -1;
	}
}

void	push_numbers_notsorted(t_data *data)
{
	int	i;
	int	j;
	int	temp;
	int	temp2;

	i = 0;
	j = -1;
	while (++j < data->max_size)
	{
		temp = data->stack_a[i];
		if (i + 1 >= data->size_a)
			temp2 = data->stack_a[0];
		else
			temp2 = data->stack_a[i + 1];
		find_number_nosorted(data, temp, i, j);
		i = get_index(data->stack_a, temp2, data->size_a);
	}
	free(data->t);
}

void	rotaterevab(t_data *data, int tempb, int tempa, int j)
{
	int	min;

	min = get_index(data->p, get_min(data->p, data->size_b), data->size_b);
	while (tempa != data->stack_a[0] && tempb != data->stack_b[0])
	{
		if (j >= data->size_a / 2 && min >= data->size_b / 2)
			rev_rotate_a_b(data);
		else if (j <= data->size_a / 2 && min <= data->size_b / 2)
			rotate_ab(data);
		else
			break ;
	}
}

void	push_toa_best_number(t_data *data)
{
	int	j;
	int	min;
	int	tempb;
	int	tempa;

	while (data->size_b)
	{
		calcul(data);
		min = get_index(data->p, get_min(data->p, data->size_b), data->size_b);
		j = get_index(data->stack_a, sml_max(data, data->stack_b[min]),
				data->size_a);
		tempb = data->stack_b[min];
		tempa = data->stack_a[j];
		rotaterevab(data, tempb, tempa, j);
		rotate(data, tempb, tempa, j);
		push_a(data);
		free(data->p);
	}
}
