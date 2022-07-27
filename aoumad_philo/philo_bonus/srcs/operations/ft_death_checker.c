/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:57:58 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/27 10:58:42 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void    *ft_death_checker(void  *arg)
{
    t_philo *philo;

    philo  = (t_philo *)arg;
    while (1)
    {
        if (ft_get_time_of_day() - philo->last_eat >= philo->time_to_die)
        {
            philo->dead_time = ft_get_time_of_day() - philo->time_reference;
            ft_affichage("is died", philo, DEAD);
            exit(TRUE);
        }
        usleep(900);
    }
    return (NULL);
}