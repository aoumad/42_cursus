/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:23:42 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/07 18:17:42 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_create_philos(t_data *data)
{
	pthread_t	thread;
	int			i;

	i = 0;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nbr_philos);
	if (ft_mutex_init(data) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	while (i < data->nbr_philos)
	{
		data->philo->all_ate = FALSE;
		ft_init_philos(&data->philo[i], data);
		data->philo[i].id = i;
		data->philo[i].l_hand = &data->forks[data->philo[i].id];
		data->philo[i].r_hand = \
			&data->forks[(data->philo[i].id + 1) % data->nbr_philos];
		pthread_create(&data->philo[i].thread, NULL, ft_routine,
			&data->philo[i]);
		pthread_detach(data->philo[i].thread);
		pthread_create(&thread, NULL, ft_death_checker, &data->philo[i]);
		pthread_detach(thread);
		i++;
		usleep(400);
	}
	ft_check_all_ate(data);
}

void	ft_init_philos(t_philo *philo, t_data *data)
{
	philo->time_reference = ft_get_time_of_day();
	philo->meals_counter = 0;
	philo->last_eat = ft_get_time_of_day();
	philo->eating_routine = FALSE;
	philo->data = data;
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
	while (data->died != DEAD)
	{
		if (ft_all_ate(&data->philo[i]) == DONE_ROUTINE)
			i++;
		if (i == data->nbr_philos - 1 && data->nbr_philos != 1)
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
