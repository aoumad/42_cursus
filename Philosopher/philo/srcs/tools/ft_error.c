/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:47:16 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/18 17:00:08 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_print_error_msg(char *error_name, char *message)
{
	ft_putstr_fd(error_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(message, 2);
}

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