/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:11:24 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/19 16:42:51 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <fcntl.h>

# define	ERROR 0
# define	VALID 1
# define	L_MAX 9223372036854775807

enum e_philo_state
{
	FALSE,
	TRUE,
	SHOULD_EAT,
	DONE_ROUTINE,
	TAKING_FORK,
	DEAD
};

typedef struct s_philo	t_philo;

typedef struct s_activity
{
	int	nbr_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_of_meals;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock_print;
	t_philo	*philo;
}	t_activity;

typedef	struct s_philo
{
	int				id;
	pthread_mutex_t	*l_hand;
	pthread_mutex_t	*r_hand;
	int				eating_routine;
	int				taking_fork;
	int				dead;
	int				meals_counter;
	int				finish_routine;
	long long		time_reference;
	pthread_t		thread;
	t_activity		*data;
}	t_philo;

//==============TOOLS=============//
void	*ft_calloc(size_t count, size_t size);
int	ft_atoi(const char *str);
