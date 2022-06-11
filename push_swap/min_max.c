/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 12:16:26 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	get_min(int *t, int size)
{
	int	min;
	int	i;

	min = t[0];
	i = 1;
	while (i < size)
	{
		if (t[i] < min)
			min = t[i];
		i++;
	}
	return (min);
}

int	get_max(int *t, int size)
{
	int	max;
	int	i;

	max = t[0];
	i = 1;
	while (i < size)
	{
		if (t[i] > max)
			max = t[i];
		i++;
	}
	return (max);
}

int	sml_max(t_data *data, int nbr)
{
	int	i;
	int	max;

	i = 0;
	max = get_max(data->stack_a, data->size_a);
	while (i < data->size_a)
	{
		if (data->stack_a[i] > nbr)
		{
			if (data->stack_a[i] < max)
				max = data->stack_a[i];
		}
		i++;
	}
	return (max);
}
