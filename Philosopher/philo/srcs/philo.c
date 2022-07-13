/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:54:16 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/13 12:02:30 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_helper_display(void)
{
	ft_putstr_fd("invalid number of arguments: \n", 2);
	ft_putstr_fd("the program should take the following args: ", 2);
	ft_putstr_fd("<number_of_philosophers> && ", 2);
	ft_putstr_fd("<time_to_die> && ", 2);
	ft_putstr_fd("<time_to_eat> && ", 2);
	ft_putstr_fd("<time_to_sleep> &&", 2);
	ft_putstr_fd("<number_of_times_each_philosopher_must_eat> (optional)", 2);
}

int main(int argc, char **argv)
{
	int	status;

	status = VALID;
	if (argc != 5 && argc != 6)
	{
		helper_display();
		return (STDERR_FILENO);
	}
	status = parsing_core();
	// if (status = VALID)
	// 	 execute_root function
}
