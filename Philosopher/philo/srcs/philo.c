/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:54:16 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/18 16:59:58 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_activity *data;
	int	status;

	data = ft_calloc(1, sizeof(t_activity));
	status = VALID;
	if (argc != 5 && argc != 6)
	{
		ft_helper_display();
		return (STDERR_FILENO);
	}
	status = ft_code_core(argc, argv, data);
	ft_mutex_detach_destroy(data);
	free(data->forks);
	free(data);
	return (0);
}
