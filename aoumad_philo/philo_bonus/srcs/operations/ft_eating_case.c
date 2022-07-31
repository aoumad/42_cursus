/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:46:06 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/31 15:48:06 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void    ft_eating_case(t_philo *philo)
{
    philo->last_eat = ft_get_time_of_day();
    if (philo->meals_counter == philo->nbr_of_meals)
    {
        philo->all_ate = DONE_ROUTINE;
        // return ;
    }
    philo->meals_counter++;
    ft_affichage("is eating", philo, TRUE);
    ft_usleep(philo->time_to_eat);
}