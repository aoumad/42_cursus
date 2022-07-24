/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:32:09 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/04 19:32:20 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

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