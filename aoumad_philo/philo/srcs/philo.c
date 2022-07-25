/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:28:00 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/25 11:49:28 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
{
    t_data  *data;
    data = ft_calloc(1, sizeof(*data));
    data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nbr_philos);
    if (ft_valid_args(argc, argv) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    ft_init_args(argc, argv, data);
    if (ft_check_pointing_cmd(argc, argv, data) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (ft_mutex_init(data) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    ft_create_philos(data);
    ft_mutex_destroy(data);
}