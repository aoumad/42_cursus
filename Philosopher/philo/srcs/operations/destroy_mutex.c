/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:58:58 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/18 18:00:10 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_mutex_detach_destroy(t_activity *data)
{
    int i;

    i = 0;
    while (i < data->nbr_philos)
        pthread_mutex_destroy(&data->forks[i++]);
    pthread_mutex_destroy(&data->lock_print);
}