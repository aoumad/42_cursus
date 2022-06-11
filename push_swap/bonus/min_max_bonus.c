/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 12:17:47 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_min(t_data *data)
{
	int	min;
	int	i;

	min = data->stack_a[0];
	i = 1;
	while (i < data->size_a)
	{
		if (data->stack_a[i] < min)
			min = data->stack_a[i];
		i++;
	}
	return (min);
}

int	get_max(t_data *data)
{
	int	max;
	int	i;

	max = data->stack_a[0];
	i = 1;
	while (i < data->size_a)
	{
		if (data->stack_a[i] > max)
			max = data->stack_a[i];
		i++;
	}
	return (max);
}

int	get_max_b(t_data *data)
{
	int	max;
	int	i;

	max = data->stack_b[0];
	i = 1;
	while (i < data->size_b)
	{
		if (data->stack_b[i] > max)
			max = data->stack_b[i];
		i++;
	}
	return (max);
}
