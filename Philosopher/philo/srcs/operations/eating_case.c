/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:06:44 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/18 11:59:07 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_eating_case(t_philo *philo)
{
    ft_affichage("is eating", philo);
    ft_usleep(philo->data->time_to_eat); // converted from micro to milleseconds
    philo->meals_counter++;
    if (philo->meals_counter == philo->data->nbr_of_meals &&
        philo->data->nbr_of_meals >= 1)
        philo->eating_routine = DONE_ROUTINE;
}