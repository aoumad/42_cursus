/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:54:20 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/19 16:52:42 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <semaphore.h>

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

void	ft_putstr_fd(char *s, int fd);
void	ft_print_error_msg(char *error_name, char *message);
int		ft_atoi(const char *str);
void	ft_init_the_args(int argc, char **argv, t_activity *data);
void    ft_init_philos(t_activity  *data);
void    ft_init_mutex(t_activity *data);

void    *ft_philo_routine(void *arg);

//=============== TOOLS ===============//
long long   ft_current_time(t_philo *philo);
long long   ft_get_time_of_day(void);
void    ft_usleep(int ms);
void    ft_affichage(char *message, t_philo *philo);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

//=========== OPERATIONS==========//
void	ft_eating_case(t_philo *philo);
void    ft_fork_left(t_philo *philo);
int		ft_get_fork(t_philo *philo, int status);
void    ft_sleeping_case(t_philo *philo);
void	ft_mutex_detach_destroy(t_activity *data);
void    *ft_dead_philo(void *arg);
void    *ft_is_hungry(void *arg);

//===========PARSING=============//
int		ft_code_core(int argc, char **argv, t_activity *data);
void	ft_check_pointing_cmd(char **argv, t_activity *data);
void	ft_init_the_args(int argc, char **argv, t_activity *data);

//===========MAIN============//
void	ft_helper_display(void);

# endif