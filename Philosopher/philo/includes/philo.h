/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:54:20 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/04 19:45:34 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define	ERROR 0
# define	VALID 1
# define L_MAX 9223372036854775807

typedef	struct s_activity
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_activity;

typedef	struct s_data
{
	
}	t_data;

void	ft_putstr_fd(char *s, int fd);
void	print_error_msg(char *error_name, char *message);
void	helper_display(void);
int		t_atoi(const char *str);
void	check_pointing_cmd(int argc, char **argv, t_activity *data);
void	init_the_args(char **argv, t_activity *data);

# endif