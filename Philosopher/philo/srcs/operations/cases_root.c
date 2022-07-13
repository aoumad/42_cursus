/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_root.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:06:41 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/13 19:14:13 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    *ft_philo_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (philo->dead != DEAD)
    {
        ft_get_fork(philo);
        //add the case if here is only the number of philos is 1
        ft_get_fork(philo);
        ft_eating_case(philo);
        ft_fork_left(philo);
        ft_sleeping_case(philo);
        ft_thinking_case(philo);
    }
}

void    *ft_dead_philo(void *arg)
{
    
}