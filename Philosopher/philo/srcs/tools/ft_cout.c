/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:48:24 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/18 11:52:56 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_affichage(char *message, t_philo *philo)
{
    long long   time;

    time = ft_current_time(philo);
    pthread_mutex_lock(&philo->data->lock_print);
    if (philo->dead != DEAD)
        printf("%lld\t%d\t%s\n", time, philo->id + 1, message);
    pthread_mutex_unlock(&philo->data->lock_print);
}