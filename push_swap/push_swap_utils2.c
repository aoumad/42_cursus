/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:12:17 by aoumad            #+#    #+#             */
/*   Updated: 2022/03/12 20:51:07 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_string(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	is_space(char c)
{
	return (is_in_string(c, "\t\n\v\f\r "));
}

int	operator(char c)
{
	return (is_in_string(c, "+-"));
}

int	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int	result;
	int	minus_check;

	result = 0;
	minus_check = 1;
	while (is_space(*str))
		str++;
	while (operator(*str))
	{
		if (*str == '-')
			minus_check *= -1;
		str++;
	}
	while (is_number(*str))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * minus_check);
}
int main(void)
{
	int num;

	num = ft_atoi("066");
	printf("%d", num);
	return (0);
}