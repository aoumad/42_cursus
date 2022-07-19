/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:08:48 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/19 16:32:57 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void    ft_helper_dispplay(void)
{
    ft_putstr_fd(" ____________________________________________________\n", 2);
	ft_putstr_fd("|            Please enter 4 or 5 arguments           |\n", 2);
	ft_putstr_fd("|____________________________________________________|\n", 2);
	ft_putstr_fd("|             [1][Number of philosophers]            |\n", 2);
	ft_putstr_fd("|             [2][Time to die]                       |\n", 2);
	ft_putstr_fd("|             [3][Time to eat]                       |\n", 2);
	ft_putstr_fd("|             [4][Time to sleep]                     |\n", 2);
	ft_putstr_fd("|             [5][Number of meals]                   |\n", 2);
	ft_putstr_fd("|____________________________________________________|\n", 2);
}

int main(int argc, char **argv)
{
    t_activity *data;

    data = ft_calloc(1, sizeof(activity));
    
    if (argc != 5 && argc != 6)
    {
        ft_helper_display();
        return (STDERR_FILENO);
    }
    ft_code_core(argc, argv, data);
    
}