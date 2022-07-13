/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:54:20 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/13 19:14:19 by aoumad           ###   ########.fr       */
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
# define	L_MAX 9223372036854775807

enum e_philo_state
{
	FALSE,
	TRUE,
	SLEEPING,
	EATING,
	THINKING,
	TAKING_FORK,
	DEAD
}
typedef struct s_activity
{
	int				nbr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_meals;
	pthread_mutex_t	*forks;
	t_philo	*philo;
}	t_activity;

typedef	struct s_philo
{
	int				id;
	pthread_mutex_t	*l_hand;
	pthread_mutex_t	*r_hand;
	int				is_sleeping;
	int				is_eating;
	int				taking_fork;
	int				dead;
}	t_philo;

void	ft_putstr_fd(char *s, int fd);
void	ft_print_error_msg(char *error_name, char *message);
void	ft_helper_display(void);
int		ft_atoi(const char *str);
void	ft_check_pointing_cmd(int argc, char **argv, t_activity *data);
void	ft_init_the_args(int argc, char **argv, t_activity *data);
void    ft_init_philos(t_activity  *data);
void    ft_init_mutex(t_activity *data);

void    *ft_philo_routine(void *arg);
# endif