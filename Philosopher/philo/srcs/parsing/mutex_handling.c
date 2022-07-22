/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:36:33 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/16 17:42:20 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_init_mutex(t_activity *data)
{
    int count;
    pthread_mutex_t *mutex;

    pthread_mutex_init(&data->lock_print, NULL);
    count = data->nbr_philos;
    mutex = malloc(count * sizeof(pthread_mutex_t));
    while (count--)
        pthread_mutex_init(&mutex[count], NULL);
    pthread_mutex_init(&data->lock_print, NULL);
}