/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:02:13 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/30 15:43:56 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void    ft_philo_routine(t_philo *philo)
{
    if (philo->id & 1)
        usleep(500);
    while (philo->finish_routine != DEAD)
    {
        ft_taking_forks(philo);
        ft_eating_case(philo);
        sem_post(philo->forks);
        sem_post(philo->forks);
        ft_sleeping_thinking(philo);
        usleep(1000);
    }
    return ;
}