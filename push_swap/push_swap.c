/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:27:55 by aoumad            #+#    #+#             */
/*   Updated: 2022/03/12 21:27:01 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_arg_to_string(char **av)
{
	char	*string;
	char	*tmp;
	int		i;

	i = 1;
	string = (char *)malloc(1);
	while (av[i])
	{
		if (!ft_check_arg(av[i]))
			exit(ft_err_and_free(NULL, "Error", 0));
		else
		{
			tmp = ft_strjoin(string, av[i]);
			free(string);
			string = ft_strjoin(tmp, " ");
			free(tmp);
			i++;
		}
	}
	return (string);
}

//stor nb's in stack a
t_stacks	ft_create_stack(char *str)
{
	t_stacks	stacks;
	char		**numbers;
	int         number;
	int			i;

	i = 0;
	numbers = ft_stacks_init(str, &stacks);
	while (numbers[i])
	{
		if (!ft_check_number(numbers[i]))
			printf("Error");
		number = ft_atoi(numbers[i]);
		if (number < -2147483648 || number > 2147483647)
			printf("Error");
		if (!ft_check_duplicates(&stacks, number))
			printf("Error");
		stacks.stack_a.array[i] = number;
		stacks.stack_a.used_size++;
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (stacks);
}

// stor nb's in 2d array
char	**ft_stacks_init(char *string, t_stacks *stacks)
{
	int		size;
	char	**numbers;

	numbers = ft_split(string, ' ');
	size = ft_count_numbers(string);
	stacks->stack_a.array = (int *)malloc(sizeof(int) * size);
	stacks->stack_b.array = (int *)malloc(sizeof(int) * size);
	stacks->stack_a.size = size;
	stacks->stack_b.size = size;
	stacks->stack_a.used_size = 0;
	stacks->stack_b.used_size = 0;
	free(string);
	return (numbers);
}

// check if av at a given point is a numbere
int	ft_check_arg(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]))
			return (1);
		i++;
	}
	return (0);
}