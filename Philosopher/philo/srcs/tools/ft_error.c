/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:47:16 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/16 15:54:02 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_print_error_msg(char *error_name, char *message)
{
	ft_putstr_fd(error_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(message, 2);
}