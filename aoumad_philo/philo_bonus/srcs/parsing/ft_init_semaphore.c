/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_semaphore.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:01:26 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/24 17:10:42 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void    ft_init_semaphore(t_data *data)
{
    data->philo->forks = sem_open("forks", O_CREAT | \
        O_EXCL, 0644, data->nbr_philos);
        printf("this is our nbr of philos here: %d\n", data->nbr_philos);
    data->philo->write_sem = sem_open("write_sem", O_CREAT | O_EXCL, 0644, 1);
    data->philo->dead_sem = sem_open("dead_sem", O_CREAT | O_EXCL, 0644, 0);
    if (data->nbr_of_meals)
        data->philo->eat_enough = sem_open("meals_counter", O_CREAT | O_EXCL, 0644, 0);
}