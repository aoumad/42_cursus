/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 07:55:33 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/02 14:11:16 by aoumad           ###   ########.fr       */
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
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <signal.h>

# define	ERROR 0
# define	VALID 1
# define	L_MAX 9223372036854775807

enum e_philo_state
{
	FALSE,
	TRUE,
	DONE_ROUTINE,
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
	long	time_reference;
    pid_t *pid_philo;
	t_philo	*philo;
	pthread_t thread;
	sem_t	*write_sem;
	sem_t	*forks;
	sem_t	*eat_enough;
	sem_t	*dead_sem;
	sem_t	*exit;
}	t_data;

typedef	struct s_philo
{
	int				philo_id;
	int				all_ate;
	int				eating_routine;
	int				taking_fork;
	int				meals_counter;
	long			time_to_kill;
    long			last_eat;
	int				finish_routine;
	pthread_t		thread;
		int	nbr_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_of_meals;
	t_data *data;
}	t_philo;

//===========TOOLS============//
void	ft_helper_display(void);
int     ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
int     ft_is_digit(char *str);
long	ft_get_time_of_day(void);
void    ft_affichage(char *message, int philo_id, t_data *data, int status);
void    ft_usleep(int ms);

//===========PARSING===========//
void    ft_init_args(int argc, char **argv, t_data *data);
int		ft_valid_args(int argc, char **argv);
void    ft_create_philos(t_data *data);
int		ft_mutex_init(t_data *data);
int		ft_check_pointing_cmd(int argc, char **argv, t_data *data);
void    ft_init_semaphore(t_data *data);
// void    ft_kill_philos(t_data *data);
void	ft_kill(t_data *data, int **pid, t_philo *philo);
void	waiting_pids(t_data *data);

//==============OPERATIONS===========//
void	ft_routine(t_philo *philo);
void	*ft_death_checker(void	*arg);
void    ft_eating_case(t_philo *philo);
void    ft_create_philos(t_data *data);
void    ft_launching_philos(t_philo *philo, t_data *data, pid_t *pid);
void    ft_sleeping_thinking(t_philo *philo);
void    ft_taking_forks(t_philo *philo);
void	*start_philo(void *arg);

# endif