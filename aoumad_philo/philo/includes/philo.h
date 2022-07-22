/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:19:32 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/22 18:19:31 by aoumad           ###   ########.fr       */
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

typedef struct s_data
{
	int	nbr_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_of_meals;
    pthread_mutex_t	*forks;
    pthread_mutex_t *lock_print;
	t_philo	*philo;
}	t_data;

typedef	struct s_philo
{
	int				id;
	pthread_mutex_t	*l_hand;
	pthread_mutex_t	*r_hand;
	int				eating_routine;
	int				taking_fork;
	int				dead;
	int				meals_counter;
    int             last_eat;
	int				finish_routine;
	long long		time_reference;
	pthread_t		thread;
	t_data		*data;
}	t_philo;

//===========TOOLS============//
void	ft_helper_display(void);
int     ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
int     ft_is_digit(char *str);

//===========PARSING===========//
void    ft_init_args(int argc, char **argv, t_data *data);
int ft_valid_args(int argc, char **argv, t_data *data);

# endif