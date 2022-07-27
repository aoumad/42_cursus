/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:29:21 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/27 11:41:22 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void    *ft_doneating_check(void *arg)
{
    t_data *data;
    int i;

    i = 0;
    data = (t_data *)arg;
    sem_wait(data->philo->write_sem);
    while (i < data->nbr_philos)
    {
        sem_post(data->philo->write_sem);
        sem_wait(data->philo->eat_enough);
        sem_wait(data->philo->write_sem);
        i++;
    }
    sem_post(data->philo->dead_sem);
    return (NULL);
}

void    ft_create_eatcheck_thread(t_data *data)
{
    if (data->nbr_of_meals)
    {
        if (pthread_create(&data->thread, NULL, &ft_doneating_check, data))
        {
            ft_putstr_fd("Error pthread", 2);
            exit(1);
        }
        pthread_detach(data->thread);
    }
}

void    ft_create_philos(t_data *data)
{
    data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nbr_philos);
    data->pid_philo = (pid_t *)malloc(sizeof(pid_t) * data->nbr_philos);
    ft_init_semaphore(data);
    ft_create_eatcheck_thread(data);
    ft_launching_philos(data);
}

int ft_all_ate(t_philo *philo)
{
    if (philo->all_ate == DONE_ROUTINE)
        return (DONE_ROUTINE);
    return (FALSE);
}

void    ft_launching_philos(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nbr_philos)
    {
        data->philo[i].time_reference = ft_get_time_of_day();
        data->philo[i].nbr_philos = data->nbr_philos;
        data->philo[i].time_to_die = data->time_to_die;
        data->philo[i].time_to_eat = data->time_to_eat;
        data->philo[i].time_to_sleep = data->time_to_sleep;
        data->philo[i].nbr_of_meals = data->nbr_of_meals;
        data->philo[i].meals_counter = 0;
        data->philo[i].all_ate = FALSE;
        data->pid_philo[i] = fork();
        data->philo[i].last_eat = ft_get_time_of_day();
        if (data->pid_philo[i] == -1)
        {
            while (--i >= 0)
                kill(data->pid_philo[i], SIGKILL);
            exit (1);
        }
        else if (data->pid_philo[i] == 0)
        {
            data->philo[i].id = i;
            pthread_create(&data->philo[i].thread, NULL, ft_death_checker, &data->philo[i]);
            pthread_detach(data->philo[i].thread);
            ft_philo_routine(&data->philo[i]);
        }
        i++;
        usleep(100);
    }
    sem_wait(data->philo->dead_sem);
    waiting_pids(data);
}