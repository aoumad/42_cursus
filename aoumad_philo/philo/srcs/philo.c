/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:28:00 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/22 18:21:36 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
{
    t_data  *data;

    data = ft_calloc(1, t_data);
    if (ft_valid_args(argc, argv, data) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    ft_init_args(argc, argv, data);
    if (ft_check_pointing_cmd(ar) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (ft_init_mutex(data) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    ft_create_philos(data);
}