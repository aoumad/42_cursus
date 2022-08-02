/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:34:10 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/02 14:11:11 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void    ft_affichage(char *message, int philo_id, t_data *data, int status)
{
    long   time;
    int dead_time;

    
    dead_time = ft_get_time_of_day() - data->time_reference;
    time = ft_get_time_of_day() - data->time_reference;
    sem_wait(data->write_sem);
    if (status == TRUE)
    {
        printf("%ld\t%d\t%s\n", time, philo_id + 1, message);
        sem_post(data->write_sem);
    }
    if (status == DONE_ROUTINE)
    {
        printf("%s\n", message);
    }
    if (status == DEAD)
    {
        printf("%d\t%d\t%s\n", dead_time, philo_id + 1, message);
    }
    return ;
}