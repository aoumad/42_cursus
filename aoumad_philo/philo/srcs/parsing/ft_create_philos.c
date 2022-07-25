/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:23:42 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/25 19:20:15 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_create_philos(t_data *data)
{
    pthread_t   thread;
    int i;

    i = 0;
    data->philo->all_ate = data->nbr_philos;
    while (i < data->nbr_philos)
    {
        data->philo[i].time_reference = ft_get_time_of_day();
        // last_eat = data->philo[i].time_reference;
        data->philo[i].id = i;
        data->philo[i].l_hand = &data->forks[data->philo[i].id];
        data->philo[i].r_hand = &data->forks[(data->philo[i].id + 1) % data->nbr_philos];
        data->philo[i].meals_counter = 0;
        data->philo[i].last_eat = data->philo[i].time_reference;
        data->philo[i].died = FALSE;
        data->philo[i].eating_routine = FALSE;
        data->philo[i].nbr_philos = data->nbr_philos;
        data->philo[i].time_to_die = data->time_to_die;
        data->philo[i].time_to_eat = data->time_to_eat;
        data->philo[i].time_to_sleep = data->time_to_die;
        data->philo[i].nbr_of_meals = data->nbr_of_meals;
        if (pthread_create(&data->philo[i].thread, NULL, ft_routine, &data->philo[i]))
            return ;
        if (pthread_create(&thread, NULL, ft_death_checker, &data->philo[i]))
            return ;
        pthread_detach(data->philo[i].thread);
        pthread_detach(thread);
        i++;
        usleep(100);
    }
}
//     while (1)
//     {
//         if (ft_death_checker(data, i) == DEAD)
//             break;
//         i++;
//         if (i == data->nbr_philos - 1)
//             i = 0;
//         usleep(100);
//     }
// }