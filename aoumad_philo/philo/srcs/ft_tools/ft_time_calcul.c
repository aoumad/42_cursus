/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:32:09 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/04 19:32:20 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long	ft_get_time_of_day(void)
{
	struct timeval	tp;
	long			time_in_ms;

	gettimeofday(&tp, NULL);
	time_in_ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return (time_in_ms);
}