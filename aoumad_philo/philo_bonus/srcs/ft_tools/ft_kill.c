/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:53:03 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/04 12:51:29 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

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