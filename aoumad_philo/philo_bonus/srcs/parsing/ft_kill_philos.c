/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:31:03 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/24 15:31:29 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void    ft_kill_philos(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nbr_philos)
    {
        kill(data->pid_philo[i], SIGKILL);
        i++;
    }
}