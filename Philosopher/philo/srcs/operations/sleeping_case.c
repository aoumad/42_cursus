/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:06:53 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/16 14:05:39 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_sleeping_case(t_philo *philo, t_activity *data)
{
    ft_affichage("is sleeping", data, philo);
    usleep(data->time_to_sleep * 1000);
}