/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 14:27:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	is_sorted(char **av, int size)
{
	int	i;
	int	c;

	c = 0;
	i = 1;
	while (i < size - 1)
	{
		if (ft_atoi(av[i]) < ft_atoi(av[i + 1]))
			c++;
		i++;
	}
	if (c == size - 2)
		return (0);
	return (1);
}
