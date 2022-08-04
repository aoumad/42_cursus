/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:39:35 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/04 19:02:51 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id & 1)
		usleep(100);
	while (philo->died != DEAD && philo->all_ate != DONE_ROUTINE)
	{
		ft_taking_forks(philo);
		ft_eating_case(philo);
		ft_sleeping_thinking(philo);
	}
	return (NULL);
}
