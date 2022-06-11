/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 12:16:03 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	calcul_rr_rrr(t_data *data, int i, int *c, int j)
{
	int	s;

	if (i >= data->size_b / 2 && j >= data->size_a / 2)
	{
		if ((data->size_b - i) < (data->size_a - j))
			s = (data->size_b - i);
		else if ((data->size_b - i) > (data->size_a - j))
			s = (data->size_a - j);
		else
			s = (data->size_b - i);
		*c = *c - s;
	}
	else if (i <= data->size_b / 2 && j <= data->size_a / 2)
	{
		if (i < j)
			s = i;
		else if (j < i)
			s = j;
		else
			s = j;
		*c = *c - s;
	}
}

void	calcul(t_data *data)
{
	int	i;
	int	j;
	int	c;

	data->p = (int *)malloc(sizeof(int) * data->size_b);
	if (!data->p)
		end(data);
	i = -1;
	j = 0;
	while (++i < data->size_b)
	{
		c = 1;
		j = get_index(data->stack_a, sml_max(data, data->stack_b[i]),
				data->size_a);
		if (i >= data->size_b / 2)
			c = c + (data->size_b - i);
		else
			c = c + i;
		if (j >= data->size_a / 2)
			c = c + (data->size_a - j);
		else
			c = c + j;
		calcul_rr_rrr(data, i, &c, j);
		data->p[i] = c;
	}
}
