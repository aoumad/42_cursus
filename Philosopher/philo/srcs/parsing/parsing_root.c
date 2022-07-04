/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_root.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:10:18 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/04 20:04:37 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	parsing_core(int argc, char **argv, t_activity *data)
{
	init_the_args(argv, data);
	check_pointing_cmd(argc, argv, data);
}

void	init_the_args(char **argv, t_activity *data)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		data->number_of_times_each_philosopher_must_eat = 0;
}
void	check_pointing_cmd(int argc, char **argv, t_activity *data)
{
	int	status;

	status = 0;
	if (data->number_of_philosophers <= 0)
		status = 1;
	if (data->time_to_die < 60)
		status = 2;
	if (data->time_to_eat < 60)
		status = 3;
	if (data->time_to_sleep < 60)
		status = 4;
	if (argv[5] && data->number_of_times_each_philosopher_must_eat == 0)
		status = 5;
	if (status)
	{
		printf("ERROR: the argument \"%d\" is invalid\n", ft_atoi(argv[status]));
		exit(EXIT_FAILURE);
	}
}