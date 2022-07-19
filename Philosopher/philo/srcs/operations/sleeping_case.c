/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:06:53 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/18 11:30:24 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_sleeping_case(t_philo *philo)
{
    ft_affichage("is sleeping", philo);
    ft_usleep(philo->data->time_to_sleep);
}