/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_root.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:10:18 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/16 17:42:25 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_parsing_core(int argc, char **argv, t_activity *data)
{
	ft_init_the_args(argc, argv, data);
	ft_check_pointing_cmd(argv, data);
	ft_init_mutex(data);
	ft_init_philos(data);
	return (0);
}

void	ft_init_the_args(int argc, char **argv, t_activity *data)
{
	data->nbr_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nbr_of_meals = ft_atoi(argv[5]);
	else
		data->nbr_of_meals = 0;
}

void	ft_check_pointing_cmd(char **argv, t_activity *data)
{
	int	status;

	status = 0;
	if (data->nbr_philos <= 0)
		status = 1;
	if (data->time_to_die < 60)
		status = 2;
	if (data->time_to_eat < 60)
		status = 3;
	if (data->time_to_sleep < 60)
		status = 4;
	if (argv[5] && data->nbr_of_meals == 0)
		status = 5;
	if (status)
	{
		printf("ERROR: the argument \"%d\" is invalid\n", ft_atoi(argv[status]));
		exit(EXIT_FAILURE);
	}
}