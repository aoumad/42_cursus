/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettimeofday.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:22:16 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/14 15:23:46 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long long   get_time_of_day(void)
{
    struct timeval  elapsed_time;

    gettimeofday(&elapsed_time, NULL);
    return((elapsed_time.tv_sec * 1000) + (elapsed_time.tv_usec / 1000));
}

long long   current_time(t_philo *philo)
{
    long long   rtn_time;

    rtn_time = get_time_of_day - philo->time_reference;
    return (rtn_time);
}
