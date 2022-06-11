/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 12:15:52 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	is_sorted_stacka(t_data *data)
{
	int	i;
	int	d;

	d = 1;
	i = 0;
	while (d == 1 && i < data->size_a - 1)
	{
		if (data->stack_a[i] > data->stack_a[i + 1])
			d = 0;
		i++;
	}
	if (d == 1)
		return (1);
	return (0);
}

int	is_int(char *arg)
{
	int	i;

	i = -1;
	if (arg[0] == '\0')
		return (0);
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[++i])
		if (!is_digit(arg[i]))
			return (0);
	return (1);
}

int	is_integer(char **av, int size)
{
	int	i;

	i = 0;
	while (++i < size)
		if (!is_int(av[i]))
			return (0);
	return (1);
}

int	is_max_int(char **av, int size)
{
	int	i;

	i = 0;
	while (++i < size)
		if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
			return (0);
	return (1);
}

int	is_duplicat(char **av, int size)
{
	int	i;
	int	j;

	j = 1;
	i = 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
