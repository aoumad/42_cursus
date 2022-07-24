/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:46:06 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/24 17:09:47 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void    ft_eating_case(t_philo *philo)
{
    philo->last_eat = ft_get_time_of_day();
    if (philo->all_ate == 0)
    {
        sem_post(philo->forks);
        sem_post(philo->forks);
        exit(EXIT_SUCCESS);
    }
    philo->all_ate--;
    ft_affichage("is eating", philo, TRUE);
    ft_usleep(philo->data->time_to_eat);
}