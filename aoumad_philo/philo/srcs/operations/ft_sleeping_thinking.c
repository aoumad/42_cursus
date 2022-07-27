/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleeping_thinking.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:45:39 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/26 11:30:32 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_sleeping_thinking(t_philo *philo)
{
    ft_affichage("is sleeping", philo, TRUE);
    ft_usleep(philo->time_to_sleep);
    // usleep(philo->time_to_sleep * 1000);
    ft_affichage("is thinking", philo, TRUE);
}