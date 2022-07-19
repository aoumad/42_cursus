/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_root.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:06:41 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/18 11:51:32 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    *ft_philo_routine(void *arg)
{
    t_philo *philo;
    int status;

    status = TRUE;
    philo = (t_philo *)arg;
    while (philo->dead != DEAD)
    {
        if (ft_get_fork(philo, status) == FALSE)
        {
            // usleep() // a matter of time
            break;
        } // still need to handle statu parameter
        ft_eating_case(philo);
        ft_fork_left(philo);
        ft_sleeping_case(philo);
        ft_affichage("is thinking", philo);
    }
    return (NULL);
}

void    *ft_dead_philo(void *arg)
{
    t_philo *philo;

    philo  = (t_philo *)arg;
    while (philo->finish_routine == FALSE)
    {
        if((philo->data->time_to_die + philo->meals_counter) < ft_get_time_of_day())
        {
            ft_affichage("died", philo);
            philo->dead = DEAD;
            philo->finish_routine = DONE_ROUTINE;
        }
        usleep(100);
    }
    return (NULL);
}

void    *ft_is_hungry(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while(philo->finish_routine == FALSE)
    {
        if (philo->meals_counter == philo->data->nbr_of_meals)
            philo->finish_routine = DONE_ROUTINE;
    }
    return (NULL);
}