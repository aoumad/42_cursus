/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 12:27:39 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	max_size;
	int	*temp;
	int	*temp2;
}	t_data;

char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(char *s);
char				*get_next_line(int fd);
char				*ft_strjoin(char *s1, char *s2);
int					is_digit(char c);
long long			ft_atoi(char *str);
int					is_integer(char **av, int size);
int					is_max_int(char **av, int size);
int					is_duplicat(char **av, int size);
int					is_sorted(char **av, int size);
void				push_a(t_data *data);
void				push_b(t_data *data);
void				rotate_a(t_data *data);
void				rotate_b(t_data *data);
void				rev_rotate_a(t_data *data);
void				rev_rotate_b(t_data *data);
void				rotate_ab(t_data *data);
void				rev_rotate_a_b(t_data *data);
void				swap_b(t_data *data);
void				swap_a(t_data *data);
void				swap_ab(t_data *data);
int					get_min(t_data *data);
int					get_max(t_data *data);
int					get_max_b(t_data *data);
void				getpos(t_data *data);
int					is_sorted_stacka(t_data *data);
int					get_index(t_data *data, int a);
void				ft_fill(char **str, int size, t_data *data);
void				ft_check(char **str, int size, t_data *data);
void				ft_read(t_data *data);
int					ft_strcmp(char *s1, char *s2);
void				end(t_data *data);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif 
#endif
