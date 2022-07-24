/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:02:13 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/24 15:23:49 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void    *ft_philo_routine(void  *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->id & 1)
        usleep(100);
    while (1)
    {
        ft_taking_forks(philo);
        ft_eating_case(philo);
        sem_post(philo->forks);
        sem_post(philo->forks);
        ft_sleeping_thinking(philo);
    }
    return (NULL);
}