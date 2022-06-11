/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 12:16:44 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill(char **str, int size, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->stack_a = (int *)malloc(sizeof(int) * (size - 1));
	if (!data->stack_a)
		exit(1);
	data->stack_b = (int *)malloc(sizeof(int));
	if (!data->stack_b)
	{
		free(data->stack_a);
		exit(1);
	}
	while (++i < size)
	{
		data->stack_a[j] = ft_atoi(str[i]);
		j++;
	}
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
	if (is_sorted_stacka(data))
	{
		free(data->stack_a);
		free(data->stack_b);
		exit(1);
	}
}

void	big_sort(t_data *data)
{
	int	min;
	int	indexmin;

	numbers_sorted(data);
	get_numbers_sorted(data);
	push_numbers_notsorted(data);
	push_toa_best_number(data);
	min = get_min(data->stack_a, data->size_a);
	indexmin = get_index(data->stack_a, min, data->size_a);
	while (min != data->stack_a[0])
	{
		if (indexmin >= data->size_a / 2)
			rev_rotate_a(data);
		else
			rotate_a(data);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (0);
	data.max_size = ac - 1;
	data.size_a = ac - 1;
	data.size_b = 0;
	ft_check(av, ac, &data);
	if (data.max_size <= 3)
		sort_3(&data);
	else if (data.max_size <= 10)
		sort_5(&data);
	else
		big_sort(&data);
	if (data.size_a)
		free(data.stack_a);
	if (data.size_b)
		free(data.stack_b);
	return (0);
}
