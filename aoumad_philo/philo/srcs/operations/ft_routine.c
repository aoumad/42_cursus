/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:39:35 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/23 18:12:32 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    *ft_routine(void *arg)
{
    t_data *data;

    data = (t_data *)arg;
    if (data->philo->id & 1)
        usleep(100);
    while (1)
    {
        ft_taking_forks(data);
        ft_eating_case(data);
        ft_sleeping_thinking(data);
    }
    return (NULL);
}