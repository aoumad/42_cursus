/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 14:27:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	fill_stack(t_data *data)
{
	int	i;
	int	j;

	free (data->stack_a);
	data->stack_a = NULL;
	data->stack_a = (int *)malloc(sizeof(int) * data->size_a + 1);
	if (!data-> stack_a)
		end(data);
	data->stack_a[0] = data->stack_b[0];
	j = -1;
	i = 1;
	while (++j < data->size_a)
		data->stack_a[i++] = data->temp[j];
	free (data->stack_b);
	data->stack_b = NULL;
	data->stack_b = (int *)malloc(sizeof(int) * data->size_b - 1);
	if (!data->size_b)
		end(data);
	i = -1;
	while (++i < data->size_b - 1)
		data->stack_b[i] = data->temp2[i];
	data->size_a++;
	data->size_b--;
}

void	push_a(t_data *data)
{
	int	i;
	int	j;

	if (data->size_b != 0)
	{
		data->temp = (int *)malloc(sizeof(int) * data->size_a);
		if (!data->temp)
			end(data);
		data->temp2 = (int *)malloc(sizeof(int) * data->size_b - 1);
		if (!data->temp2)
		{
			free(data->temp);
			end(data);
		}
		j = -1;
		while (++j < data->size_a)
			data->temp[j] = data->stack_a[j];
		j = -1;
		i = 1;
		while (++j < data->size_b)
			data->temp2[j] = data->stack_b[i++];
		fill_stack(data);
		free (data->temp);
		free (data->temp2);
	}
}
