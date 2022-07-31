/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:34:10 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/30 15:17:17 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void    ft_affichage(char *message, t_philo *philo, int status)
{
    long   time;

    time = ft_get_time_of_day() - philo->time_reference;
    sem_wait(philo->write_sem);
    if (status == TRUE)
    {
        printf("%ld\t%d\t%s\n", time, philo->id + 1, message);
        sem_post(philo->write_sem);
    }
    if (status == DONE_ROUTINE)
    {
        printf("%s\n", message);
        // sem_wait(philo->eat_enough);
    }
    if (status == DEAD)
    {
        printf("%d\t%d\t%s\n", philo->dead_time, philo->id + 1, message);
        // sem_post(philo->dead_sem);
    }
    return ;
}