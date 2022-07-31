/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:57:58 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/31 16:04:39 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void    *ft_death_checker(void  *arg)
{
    t_philo *philo;

    philo  = (t_philo *)arg;
    // printf("get time of day is: %ld\n", ft_get_time_of_day());
    // printf("last eat: %ld\n", philo->last_eat);
    // printf("time to die: %d\n", philo->time_to_die);
    while (1)
    {
    // printf("get time of day is: %ld\n", ft_get_time_of_day());
    // printf("last eat: %ld\n", philo->last_eat);
    // printf("time to die: %d\n", philo->time_to_die);
        // if (ft_get_time_of_day() - philo->last_eat >= (long)philo->time_to_die)
        if (philo->last_eat + (long)philo->time_to_die < ft_get_time_of_day())
        {
            philo->dead_time = ft_get_time_of_day() - philo->time_reference;
            ft_affichage("is died", philo, DEAD);
            philo->finish_routine = DEAD;
            exit(TRUE);
        }
        usleep(5000);
    }
    return (NULL);
}