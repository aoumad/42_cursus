/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:06:47 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/14 17:32:47 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int ft_get_fork(t_activity *info, t_philo *philo, int status)
{
    pthread_mutex_lock(philo->l_hand);
    if (info->nbr_philos == 1)
        status = FALSE;
    pthread_mutex_lock(philo->r_hand);
    pthread_mutex_lock(&info->lock_print);
    if (philo->dead != DEAD)
    {
        ft_affichage("has taken a fork", info, philo);
        if (status != FALSE)
            ft_affichage("has taken a fork", info, philo);
    }
    pthread_mutex_unlock(&info->lock_print); // i still need to check if i should unlock here or in another case
    return (status);
}