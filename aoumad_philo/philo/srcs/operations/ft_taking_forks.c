/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taking_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:45:24 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/23 16:09:11 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_taking_forks(t_data *data)
{
    int status;

    status =  0;
    if (data->nbr_philos == 1)
        status = 1;
    pthread_mutex_lock(data->philo->l_hand);
    ft_affichage("has taken a fork", data->philo, TRUE);
    pthread_mutex_unlock(data->philo->l_hand);
    if (status != 1)
    {
        pthread_mutex_lock(data->philo->r_hand);
        ft_affichage("has taken a fork", data->philo, TRUE);
        pthread_mutex_unlock(data->philo->r_hand);
    }
}