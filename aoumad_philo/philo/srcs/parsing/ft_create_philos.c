/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:23:42 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/04 18:49:01 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_create_philos(t_data *data)
{
	pthread_t	thread;
	int			i;
	long		time_reference;

	i = 0;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nbr_philos);
	time_reference = ft_get_time_of_day();
	while (i < data->nbr_philos)
	{
		data->philo->all_ate = FALSE;
		data->philo[i].id = i;
		ft_init_philos(data->philo + i, time_reference, data);
		if (pthread_create(&data->philo[i].thread, NULL,
				ft_routine, &data->philo[i]))
			return ;
		if (pthread_create(&thread, NULL, ft_death_checker, &data->philo[i]))
			return ;
		pthread_detach(data->philo[i].thread);
		pthread_detach(thread);
		i++;
		usleep(500);
	}
	ft_check_all_ate(data);
}

void	ft_init_philos(t_philo *philo, long time_reference, t_data *data)
{
	philo->time_reference = time_reference;
	philo->l_hand = &data->forks[data->philo[i].id];
	philo->r_hand = \
		&data->forks[(data->philo[i].id + 1) % data->nbr_philos];
	philo->meals_counter = 0;
	philo->last_eat = data->philo[i].time_reference;
	philo->died = FALSE;
	philo->eating_routine = FALSE;
	philo->nbr_philos = data->nbr_philos;
	philo->time_to_die = data->time_to_die;
	philo->time_to_eat = data->time_to_eat;
	philo->time_to_sleep = data->time_to_sleep;
	philo->nbr_of_meals = data->nbr_of_meals;
}

void	ft_check_all_ate(t_data *data)
{
	int	i;

	i = 0;
	while (data->philo[i].died != DEAD)
	{
		if (ft_all_ate(&data->philo[i]) == DONE_ROUTINE)
			i++;
		if (i == data->nbr_philos - 1)
		{
			ft_affichage("All philosophers ate", data->philo, DONE_ROUTINE);
			break ;
		}
		usleep(100);
	}
}

int	ft_all_ate(t_philo *philo)
{
	if (philo->all_ate == DONE_ROUTINE && philo->nbr_of_meals != 0)
		philo->eating_routine = DONE_ROUTINE;
	return (philo->eating_routine);
}
