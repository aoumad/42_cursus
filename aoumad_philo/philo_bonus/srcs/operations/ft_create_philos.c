/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:29:21 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/24 17:08:54 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void    ft_create_philos(t_data *data)
{
    data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nbr_philos);
    data->pid_philo = (pid_t *)malloc(sizeof(pid_t) * data->nbr_philos);
    data->philo->time_reference = ft_get_time_of_day();
    ft_init_semaphore(data);
    ft_init_semaphore(data);
    ft_launching_philos(data);
}

void    ft_launching_philos(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nbr_philos)
    {
        data->philo[i].id = i;
        data->pid_philo[i] = fork();
        if (data->pid_philo[i] == -1)
        {
            while (--i >= 0)
                kill(data->pid_philo[i], SIGKILL);
            exit (1);
        }
        else if (data->pid_philo[i] == 0)
        {
            data->philo[i].last_eat = ft_get_time_of_day();
            pthread_create(&data->philo[i].thread, NULL, ft_philo_routine, &data->philo[i]);
            pthread_detach(data->philo[i].thread);
            while (1)
            {
                ft_death_checker(&data->philo[i], data);
                usleep(100);
            }
        }
        i++;
        usleep(100);
    }
}