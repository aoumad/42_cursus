/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:47:16 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/13 12:02:37 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_print_error_msg(char *error_name, char *message)
{
	ft_putstr(error_name, 2);
	ft_putstr(": ", 2);
	ft_putstr(message, 2);
}