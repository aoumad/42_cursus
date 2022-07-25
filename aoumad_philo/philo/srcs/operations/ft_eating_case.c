/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:05:11 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/25 19:38:44 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_eating_case(t_philo *philo)
{
    if (philo->meals_counter == philo->nbr_of_meals)
        philo->all_ate--;
    philo->meals_counter++;
    printf("before: %d\n", philo->all_ate);
            printf("after: %d\n", philo->all_ate);
    ft_affichage("is eating", philo, TRUE);
    // ft_usleep(philo->time_to_eat);
    usleep(philo->time_to_eat * 1000);
    philo->last_eat = ft_get_time_of_day();
}