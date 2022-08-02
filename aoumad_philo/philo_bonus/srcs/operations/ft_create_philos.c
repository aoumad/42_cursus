/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:29:21 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/02 13:58:19 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

// void    ft_create_philos(t_data *data)
// {
//     data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nbr_philos);
//     ft_init_semaphore(data);
//     // ft_create_eatcheck_thread(data);
//     ft_launching_philos(data);
// }

// int ft_all_ate(t_philo *philo)
// {
//     if (philo->all_ate == DONE_ROUTINE)
//         return (DONE_ROUTINE);
//     return (FALSE);
// }

// void    ft_launching_philos(t_data *data)
// {
//     int i;

//     i = 0;
//     data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nbr_philos);
//     data->pid_philo = (pid_t *)malloc(sizeof(pid_t) * data->nbr_philos);
//     while (i < data->nbr_philos)
//     {
//         data->philo[i].time_reference = ft_get_time_of_day();
//         data->philo[i].nbr_philos = data->nbr_philos;
//         data->philo[i].time_to_die = data->time_to_die;
//         data->philo[i].time_to_eat = data->time_to_eat;
//         data->philo[i].time_to_sleep = data->time_to_sleep;
//         data->philo[i].nbr_of_meals = data->nbr_of_meals;
//         data->philo[i].finish_routine = FALSE;
//         data->philo[i].meals_counter = 0;
//         data->philo[i].all_ate = FALSE;
//         data->pid_philo[i] = fork();
//         data->philo[i].id = i;
//         data->philo[i].last_eat = ft_get_time_of_day();
//         if (data->pid_philo[i] == -1)
//         {
//             while (--i >= 0)
//                 kill(data->pid_philo[i], SIGKILL);
//             exit (1);
//         }
//         else if (data->pid_philo[i] == 0)
//         {
//             pthread_create(&data->philo[i].thread, NULL, ft_death_checker, &data->philo[i]);
//             pthread_detach(data->philo[i].thread);
            // ft_philo_routine(&data->philo[i]);
//             // usleep(100);
//         }
//         i++;
//     }
//     // sem_wait(data->philo->dead_sem);
//     waiting_pids(data);
// }

void	create_philos(t_philo *philo, t_data *data)
{
	int		i;
	pid_t	*pid;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * data->nbr_of_meals);
	pid = (pid_t *)malloc(sizeof(int) * data->nbr_philos);
	i = 0;
	data->time_reference = ft_get_time_of_day();
	ft_launching_philos(philo, data, pid);
	sem_wait(data->exit);
	ft_kill(data, &pid, philo);
}

void	ft_kill(t_data *data, int **pid, t_philo *philo)
{
	int	i;

	i = 0;
	sem_close(data->eat_enough);
	sem_close(data->forks);
	sem_close(data->write_sem);
	sem_close(data->dead_sem);
	sem_close(data->exit);
	while (i < data->nbr_philos)
	{
		kill((*pid)[i], SIGKILL);
		i++;
	}
	free(philo);
	free(*pid);
}

void    ft_launching_philos(t_philo *philo, t_data *data, pid_t *pid)
{
    int			i;
	pthread_t	thread;

	i = 0;
	while (i < data->nbr_philos)
	{
		pid[i] = fork();
		philo[i].philo_id = i + 1;
		philo[i].data = data;
		if (pid[i] == 0)
		{
			start_philo(&philo[i]); // hna fin wslt
			break ;
		}
		i++;
	}
	if (philo->data->nbr_of_meals != -1)
	{
		if (pthread_create(&thread, NULL, ft_death_checker, philo) != 0)
		{
			printf("Unable to create a thread!!");
			exit(TRUE);
		}
		pthread_detach(thread);
	}
}

void	*start_philo(void *arg)
{
	t_philo		*philo;
	pthread_t	thread;

	philo = (t_philo *)arg;
	philo->time_to_kill = philo->last_eat + (long)philo->time_to_die;
	if (pthread_create(&thread, NULL, &ft_death_checker, philo) != 0)
	{
		printf("Unable to create a thread\n");
		exit(TRUE);
	}
	pthread_detach(thread);
	if (philo->philo_id % 2 == 0)
	{
		usleep(100);
	}
	philo->meals_counter = 0 ;
	while (1)
		ft_routine(philo);
	return (NULL);
}