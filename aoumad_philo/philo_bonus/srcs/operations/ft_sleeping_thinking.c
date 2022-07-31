/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleeping_thinking.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:45:34 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/29 15:27:40 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void    ft_sleeping_thinking(t_philo *philo)
{
    ft_affichage("is sleeping", philo, TRUE);
    ft_usleep(philo->time_to_sleep);
    // usleep(philo->time_to_sleep * 1000);
    ft_affichage("is thinking", philo, TRUE);
}