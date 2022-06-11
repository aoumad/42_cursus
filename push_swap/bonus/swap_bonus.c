/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 12:17:59 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	swap_b(t_data *data)
{
	int	k;

	if (data->size_b > 1)
	{
		k = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = k;
	}
}

void	swap_a(t_data *data)
{
	int	k;

	if (data->size_a > 1)
	{
		k = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = k;
	}
}

void	swap_ab(t_data *data)
{
	swap_a(data);
	swap_b(data);
}

void	rev_rotate_a_b(t_data *data)
{
	rev_rotate_a(data);
	rev_rotate_b(data);
}
