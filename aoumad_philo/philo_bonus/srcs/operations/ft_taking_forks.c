/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taking_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:45:23 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/24 14:48:25 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void    ft_taking_forks(t_philo *philo)
{
        sem_wait(philo->forks);
        ft_affichage("has taken a fork", philo, TRUE);
        sem_wait(philo->forks);
        ft_affichage("has taken a fork", philo, TRUE);
}