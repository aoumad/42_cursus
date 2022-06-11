/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 12:17:53 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	fill_stack1(t_data *data)
{
	int	i;
	int	j;

	free (data->stack_b);
	data->stack_b = NULL;
	data->stack_b = (int *)malloc(sizeof(int) * data->size_b + 1);
	if (!data->stack_b)
		end(data);
	data->stack_b[0] = data->stack_a[0];
	j = -1;
	i = 1;
	while (++j < data->size_b)
		data->stack_b[i++] = data->temp[j];
	free (data->stack_a);
	data->stack_a = NULL;
	data->stack_a = (int *)malloc(sizeof(int) * data->size_a - 1);
	if (!data->stack_a)
		end(data);
	i = -1;
	while (++i < data->size_a - 1)
		data->stack_a[i] = data->temp2[i];
	data->size_b++;
	data->size_a--;
}

void	push_b(t_data *data)
{
	int	i;
	int	j;

	if (data->size_a != 0)
	{
		data->temp = (int *)malloc(sizeof(int) * data->size_b);
		if (!data->temp)
			end(data);
		data->temp2 = (int *)malloc(sizeof(int) * data->size_a - 1);
		if (!data->temp2)
		{
			free(data->temp);
			end(data);
		}
		j = -1;
		while (++j < data->size_b)
			data->temp[j] = data->stack_b[j];
		j = -1;
		i = 1;
		while (++j < data->size_a)
			data->temp2[j] = data->stack_a[i++];
		fill_stack1(data);
		free (data->temp);
		free (data->temp2);
	}
}
