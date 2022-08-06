/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:58:03 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/31 21:59:03 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_affichage(char *message, t_philo *philo, int status)
{
    long   time;
    (void)message;
    time = ft_get_time_of_day() - philo->time_reference;
    if (status == TRUE && philo->died != DEAD)
    {
        pthread_mutex_lock(&philo->lock_print);
        printf("%ld\t%d\t%s\n", time, philo->id + 1, message);
        pthread_mutex_unlock(&philo->lock_print);
    }
    if (status == DONE_ROUTINE)
        printf("%s\n", message);
    if (status == DEAD)
    {
        printf("%d\t%d\t%s\n", philo->dead_time, philo->id + 1, message);
        pthread_mutex_lock(&philo->lock_print);
    }
}