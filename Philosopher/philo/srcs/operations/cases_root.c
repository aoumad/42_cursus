/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_root.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:06:41 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/14 17:41:24 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    *ft_philo_routine(void *arg)
{
    t_philo *philo;
    t_activity  *data;
    int status;

    status = TRUE;
    philo = (t_philo *)arg;
    while (philo->dead != DEAD)
    {
        if (ft_get_fork(philo, data, status) == FALSE)
        {
            // usleep() // a matter of time
            break;
        } // still need to handle statu parameter
        ft_eating_case(philo, data);
        ft_fork_left(philo);
        ft_sleeping_case(philo);
        ft_thinking_case(philo);
    }
}

void    *ft_dead_philo(void *arg)
{
    
}