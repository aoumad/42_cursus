/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:11:59 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/19 23:15:43 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		*str;

	argc--;
	if (argc != 0)
	{
		str = ft_arg_to_string(argv);
		stacks = ft_create_stack(str);
		if (ft_check_sorted(&stacks.stack_a))
			return (ft_err_and_free(&stacks, NULL, 0));
		else if (stacks.stack_a.size == 2)
			ft_sa_or_sb(&stacks.stack_a, ON, 'a');
		else if (stacks.stack_a.size == 3)
			sort_3(&stacks);
		else if (stacks.stack_a.size <= 10)
			sort_10(&stacks);
		else
			big_sort(&stacks);
		return (ft_err_and_free(&stacks, NULL, 0));
	}
	return (0);
}
