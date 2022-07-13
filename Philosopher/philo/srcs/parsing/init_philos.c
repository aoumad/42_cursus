/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:29:43 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/13 19:14:26 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_init_philos(t_activity  *data)
{
    int         i;
    t_philo     *philo;
    pthread_t   thread_id;

    i = 0;
    //still should search about creation_time
    philo = malloc(sizeof(t_philo) * data->nbr_philos);
    while (i < data->nbr_philos)
    {
        philo[i].id = i;
        philo[i].l_hand = &data->forks[philo[i].id];
        philo[i].r_hand = &data->forks[(philo[i].id + 1)] % data->nbr_philos;
        philo[i].dead = FALSE;
        philo[i].is_eating = FALSE;
        philo[i].is_sleeping = FALSE;
        philo[i].taking_fork = FALSE;
        pthread_create(&philo[i], NULL, ft_philo_routine, &philo[i]);
        pthread_create(thread_id, NULL, ft_dead_philo, )
        i++;
    }
}