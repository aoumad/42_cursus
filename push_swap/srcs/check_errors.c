/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:27:55 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/19 17:22:03 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

//it prints out ERROR msg and frees the stack_s
int ft_err_and_free(t_stacks *stacks, char *message, int return_value)
{
    if (stacks)
    {
        if (stacks->stack_a.array)
            free(stacks->stack_a.array);
        if (stacks->stack_b.array)
            free(stacks->stack_b.array);
    }
    if (message != NULL)
        write(2, "Error\n", 6);
    return (return_value);
}

// count numbers after splitting it
int ft_count_numbers(char *string)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (string[i])
    {
        if (string[i] == ' ')
            count++;
        i++;
    }
    return (count);
}

int ft_check_duplicates(t_stacks *stacks, int number)
{
    int size;
    int i;

    i = 0;
    size = stacks->stack_a.used_size;
    if (size == 0)
        return (1);
    while (i < size)
    {
        if (stacks->stack_a.array[i] == number)
            return (0);
        i++;
    }
    return (1);
}

int ft_check_sorted(t_array *array)
{
    int i;
    int *tmp;

    i = 0;
    tmp = array->array;
    while (i < array->used_size - 1)
    {
        if (tmp[i] > tmp[i + 1])
            return (0);
        i++;
    }
    return (1);
}

int	ft_check_number(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '-')
		i++;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}