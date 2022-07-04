/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:47:16 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/04 17:51:54 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	print_error_msg(char *error_name, char *message)
{
	ft_putstr(error_name, 2);
	ft_putstr(": ", 2);
	ft_putstr(message, 2);
}