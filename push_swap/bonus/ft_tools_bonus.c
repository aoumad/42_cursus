/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 14:27:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long long	ft_atoi(char *str)
{
	int		i;
	long	r;
	int		s;

	i = 0;
	r = 0;
	s = 1;
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (s * r);
}

int	get_index(t_data *data, int a)
{
	int	i;

	i = 0;
	while (i < data->size_a)
	{
		if (data->stack_a[i] == a)
			return (i);
		i++;
	}
	return (-1);
}

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

void	end(t_data *data)
{
	if (data->size_a)
		free(data->stack_a);
	if (data->size_b)
		free(data->stack_b);
	exit(1);
}
