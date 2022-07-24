/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:57:58 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/24 11:58:43 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

int ft_death_checker(t_philo *philo, t_data *data)
{
    if (ft_get_time_of_day() - philo->last_eat >= data->time_to_die)
    {
        philo->dead_time = ft_get_time_of_day() - philo->time_reference;
        ft_affichage("is died", philo, DEAD);
        return (DEAD);
    }
    if (philo->all_ate == 0)
    {
        ft_affichage("All philosophers ate", philo, DONE_ROUTINE);
        return (DONE_ROUTINE);
    }
    return (0);
}