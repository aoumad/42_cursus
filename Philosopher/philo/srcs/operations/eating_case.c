/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:06:44 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/15 09:40:20 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_eating_case(t_philo *philo, t_activity *data)
{
    ft_affichage("is eating", data, philo);
    usleep(data->time_to_eat * 1000); // converted from micro to milleseconds
    philo->meals_counter++;
    if (philo->meals_counter == data->nbr_of_meals && data->nbr_of_meals >= 1)
        philo->eating_routine = DONE_ROUTINE;
}