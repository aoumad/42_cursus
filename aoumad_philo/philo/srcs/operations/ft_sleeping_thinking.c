/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleeping_thinking.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:45:39 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/23 16:08:57 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_sleeping_thinking(t_data *data)
{
    ft_affichage("is sleeping", data->philo, TRUE);
    ft_usleep(data->time_to_sleep);
    ft_affichage("is thinking", data->philo, TRUE);
}