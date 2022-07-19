/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:29:43 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/18 18:01:11 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_init_philos(t_activity  *data)
{
    int         i;
    pthread_t   thread_id;

    i = 0;
    data->philo = malloc(sizeof(t_philo) * data->nbr_philos);
    data->philo->time_reference = ft_get_time_of_day();
    while (i < data->nbr_philos)
    {
        data->philo[i].id = i;
        data->philo[i].l_hand = &data->forks[data->philo[i].id];
        data->philo[i].r_hand = &data->forks[(data->philo[i].id + 1) % data->nbr_philos];
        data->philo[i].dead = FALSE;
        data->philo[i].finish_routine = FALSE;
        data->philo[i].meals_counter = 0;
        data->philo[i].eating_routine = SHOULD_EAT;
        data->philo[i].taking_fork = FALSE;
        pthread_create(&data->philo[i].thread, NULL, ft_philo_routine, &data->philo[i]);
        pthread_detach(data->philo[i].thread);
        pthread_create(&thread_id, NULL, ft_dead_philo, &data->philo[i]);
        pthread_detach(thread_id);
        i++;
        usleep(100);
    }
}