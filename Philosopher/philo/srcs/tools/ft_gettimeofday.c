/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettimeofday.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:22:16 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/18 11:46:32 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long long   ft_get_time_of_day(void)
{
    struct timeval  elapsed_time;

    gettimeofday(&elapsed_time, NULL);
    return((elapsed_time.tv_sec * 1000) + (elapsed_time.tv_usec / 1000));
}

long long   ft_current_time(t_philo *philo)
{
    long long   rtn_time;

    rtn_time = (ft_get_time_of_day() - philo->time_reference);
    return (rtn_time);
}

void    ft_usleep(int ms)
{
    long long time;

    time = ft_get_time_of_day();
    usleep(ms * 920);
    // current_time is less than the previous time + time that i wanted to sleep?
    while (ft_get_time_of_day() < time + ms)
        usleep(ms * 2);
}