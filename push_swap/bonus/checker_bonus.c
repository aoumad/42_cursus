/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 14:26:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_error(t_data *data)
{
	write(2, "Error\n", 6);
	end(data);
}

void	check_instruct(char *op, t_data *data)
{
	if (!ft_strcmp("sa\n", op))
		swap_a(data);
	else if (!ft_strcmp("sb\n", op))
		swap_b(data);
	else if (!ft_strcmp("ss\n", op))
		swap_ab(data);
	else if (!ft_strcmp("ra\n", op))
		rotate_a(data);
	else if (!ft_strcmp("rb\n", op))
		rotate_b(data);
	else if (!ft_strcmp("rr\n", op))
		rotate_ab(data);
	else if (!ft_strcmp("pa\n", op))
		push_a(data);
	else if (!ft_strcmp("pb\n", op))
		push_b(data);
	else if (!ft_strcmp("rra\n", op))
		rev_rotate_a(data);
	else if (!ft_strcmp("rrb\n", op))
		rev_rotate_b(data);
	else if (!ft_strcmp("rrr\n", op))
		rev_rotate_a_b(data);
	else
		ft_error(data);
}

void	ft_read(t_data *data)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		check_instruct(operation, data);
		free(operation);
		operation = get_next_line(0);
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
	if (is_sorted_stacka(&data))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (data.size_a)
		free(data.stack_a);
	if (data.size_b)
		free(data.stack_b);
	return (0);
}
