/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:11:59 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/20 23:01:06 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_arg_to_string(char **argv)
{
	char	*string;
	char	*tmp;
	int		i;

	i = 1; // to exclude the "./push_swap" vector
	string = (char *)malloc(1);  // to join something into this string it must be allocated
	string[0] = 0;
	while (argv[i])
	{
		if (!ft_check_arg(argv[i]))
		{
			exit(ft_err_and_free(NULL, "Error", 0));
		}
		else
		{
			tmp = ft_strjoin(string, argv[i]);
			free(string);
			string = ft_strjoin(tmp, " ");
			free(tmp);
			i++;
		}
	}
	return (string);
}

//it checks if the argument vector given point is a number
int	ft_check_arg(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

//store numbers in stack a
t_stacks	ft_create_stack(char *str)
{
	t_stacks	stacks;
	char		**numbers;
	long long	number;
	int			i;

	i = 0;
	numbers = ft_stacks_init(str, &stacks);
	while (numbers[i])
	{
	   	if (!ft_check_number(numbers[i]))
		   	exit(ft_err_and_free(&stacks, "Error", 0));
		number = ft_atoi(numbers[i]);
		if (number < -2147483648 || number > 2147483647)
			exit(ft_err_and_free(&stacks, "Error", 0));
		if (!ft_check_duplicates(&stacks, number))
			exit(ft_err_and_free(&stacks, "Error", 0));
		stacks.stack_a.array[i] = number;
		stacks.stack_a.used_size++;
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (stacks);
}

char	**ft_stacks_init(char *string, t_stacks *stacks)
{
	int		size;
	char	**numbers;

	numbers = ft_split(string, ' ');
	size = ft_count_numbers(string);
	stacks->stack_a.array = (int *)malloc(sizeof(int) * size);
	stacks->stack_b.array = (int *)malloc(sizeof(int) * size);
	stacks->stack_a.t = (int *)malloc(sizeof(int) * size);
	stacks->stack_a.size = size;
	stacks->stack_b.size = size;
	stacks->stack_a.used_size = 0;
	stacks->stack_b.used_size = 0;
	free(string);
	return (numbers);
}

