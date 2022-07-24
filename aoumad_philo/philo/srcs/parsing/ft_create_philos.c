/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:23:42 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/23 18:15:42 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_create_philos(t_data *data)
{
    int last_eat;
    int i;

    i = 0;
    data->philo = malloc(sizeof(t_philo) * data->nbr_philos);
    data->philo->time_reference = ft_get_time_of_day();
    last_eat = data->philo->time_reference;
    data->philo->all_ate = data->nbr_philos;
    while (i < data->nbr_philos)
    {
        data->philo[i].id = i;
        data->philo[i].l_hand = &data->forks[data->philo[i].id];
        data->philo[i].r_hand = &data->forks[(data->philo[i].id + 1) % data->nbr_philos];
        data->philo[i].meals_counter = 0;
        data->philo[i].last_eat = last_eat;
        if (pthread_create(&data->philo[i].thread, NULL, ft_routine, &data->philo[i]))
            return ;
        pthread_detach(data->philo[i].thread);
        i++;
    }
    while (1)
    {
        if (ft_death_checker(&data->philo[i], data) == DEAD)
            break;
        i++;
        if (i == data->nbr_philos - 1)
            i = 0;
        usleep(100);
    }
}