/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 12:17:19 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	getpos(t_data *data)
{
	int	i;
	int	j;
	int	pos;
	int	*ptr;

	i = 0;
	ptr = malloc((data->size_a) * sizeof(int));
	if (!ptr)
		exit(1);
	while (i < data->size_a)
	{
		j = 0;
		pos = 0;
		while (j < data->size_a)
		{
			if (data->stack_a[i] > data->stack_a[j])
				pos++;
			j++;
		}
		ptr[i] = pos + 1;
		i++;
	}
	free(data->stack_a);
	data->stack_a = ptr;
}

void	ft_fill(char **str, int size, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->stack_a = (int *)malloc(sizeof(int) * (size - 1));
	data->stack_b = (int *)malloc(sizeof(int));
	while (++i < size)
	{
		data->stack_a[j] = ft_atoi(str[i]);
		j++;
	}
	getpos(data);
}

void	ft_check(char **str, int size, t_data *data)
{
	if (!is_integer(str, size) || !is_max_int(str, size)
		|| !is_duplicat(str, size))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	ft_fill(str, size, data);
	ft_read(data);
	if (is_sorted_stacka(data))
	{
		free(data->stack_a);
		write(1, "OK\n", 3);
		exit(1);
	}
}
