/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:39:35 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/25 19:17:17 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    *ft_routine(void *arg)
{
    t_philo *philo;
    philo = (t_philo *)arg;
    if (philo->id & 1)
        usleep(500);
    while (philo->died != DEAD && philo->all_ate != DONE_ROUTINE)
    {
        ft_taking_forks(philo);
        if (philo->nbr_philos == 1)
        {
            usleep(1000000);
            break ;
        }
        ft_eating_case(philo);
        ft_sleeping_thinking(philo);
    }
    return (NULL);
}