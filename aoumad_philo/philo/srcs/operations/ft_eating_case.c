/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:05:11 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/23 16:08:46 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_eating_case(t_data *data)
{
    if (data->philo->meals_counter == data->nbr_of_meals)
        data->philo->all_ate--;
    ft_affichage("is eating", data->philo, TRUE);
    ft_usleep(data->time_to_eat);
    data->philo->meals_counter++;
    data->philo->last_eat = ft_get_time_of_day();
}