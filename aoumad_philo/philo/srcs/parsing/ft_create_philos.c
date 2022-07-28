/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:23:42 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/28 18:42:29 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    ft_create_philos(t_data *data)
{
    pthread_t   thread;
    int i;

    i = 0;
    data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nbr_philos);
    while (i < data->nbr_philos)
    {
        data->philo->all_ate = FALSE;
        data->philo[i].time_reference = ft_get_time_of_day();
        data->philo[i].id = i;
        data->philo[i].l_hand = &data->forks[data->philo[i].id];
        data->philo[i].r_hand = &data->forks[(data->philo[i].id + 1) % data->nbr_philos];
        data->philo[i].meals_counter = 0;
        data->philo[i].last_eat = data->philo[i].time_reference;
        data->philo[i].died = FALSE;
        data->philo[i].eating_routine = FALSE;
        data->philo[i].nbr_philos = data->nbr_philos;
        data->philo[i].time_to_die = data->time_to_die;
        data->philo[i].time_to_eat = data->time_to_eat;
        data->philo[i].time_to_sleep = data->time_to_sleep;
        data->philo[i].nbr_of_meals = data->nbr_of_meals;
            // printf("philo has id : %d\n", data->philo[i].id);
        if (pthread_create(&data->philo[i].thread, NULL, ft_routine, data->philo + i))
            return ;
        if (pthread_create(&thread, NULL, ft_death_checker, &data->philo[i]))
            return ;
        pthread_detach(data->philo[i].thread);
        pthread_detach(thread);
        i++;
        // usleep(100);
    }
    i = 0;
    while (1)
        {
            if (ft_all_ate(&data->philo[i]) == DONE_ROUTINE)
                i++;
            if (i == data->nbr_philos - 1)
            {
                ft_affichage("All philosophers ate", data->philo, DONE_ROUTINE);
                break;
            }
            usleep(100);
        }
    // if (data->nbr_of_meals  != 0)
    // {
    //     pthread_create(&thread, NULL, ft_all_ate, &data->philo);
    //     pthread_detach(thread);
    // }
}
int ft_all_ate(t_philo *philo)
{
    if (philo->all_ate == DONE_ROUTINE && philo->nbr_of_meals != 0)
        philo->eating_routine = DONE_ROUTINE;
    return (philo->eating_routine);
}

// void    *ft_all_ate(void    *arg)
// {
//     t_philo *philo;

//     philo = (t_philo *)arg;
//     while (philo->died != DEAD)
//     {
//         printf("hahahahhaha\n");
//         if (philo->all_ate == 0)
//             philo->eating_routine = DONE_ROUTINE;
//     }
//     return (NULL);
// }