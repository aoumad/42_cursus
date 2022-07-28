/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:46:06 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/28 16:20:30 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void    ft_eating_case(t_philo *philo)
{
    philo->last_eat = ft_get_time_of_day();
    if (philo->meals_counter == philo->nbr_philos)
    {
        philo->all_ate = DONE_ROUTINE;
        sem_post(philo->forks);
        sem_post(philo->forks);
        return ;
        // exit(EXIT_SUCCESS);
    }
    philo->meals_counter++;
    ft_affichage("is eating", philo, TRUE);
    // ft_usleep(philo->time_to_eat);
    usleep(philo->time_to_eat * 1000);
}