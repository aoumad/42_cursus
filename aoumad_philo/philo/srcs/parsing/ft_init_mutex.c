/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:27:32 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/22 18:20:40 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int ft_mutex_init(t_data *data)
{
    int count;

    count = data->nbr_philos;
    if (pthread_mutex_init(data->lock_print, NULL))
        return (EXIT_FAILURE);
    while (count--)
    {
        if (pthread_mutex_init(data->forks, NULL))
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}