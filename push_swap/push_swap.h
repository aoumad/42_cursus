/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:11:59 by aoumad            #+#    #+#             */
/*   Updated: 2022/03/10 14:11:59 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define ON 1
#define OFF 0

typedef struct array
{
	int	size;
	int	used_size;
	int	*array;
}				t_array;

typedef struct stack
{
	t_array	stack_a;
	t_array	stack_b;
}				t_stacks;

//libft functions
int     	ft_isdigit(int c);
void		ft_putendl_fd(char *s, int fd);
char    	*ft_strdup(const char *s);
size_t  	ft_strlen(const char *s);
int     	ft_strcmp(const char *s1, const char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_atoi(char *str);
int			is_number(char c);
int			operator(char c);
int			is_space(char c);
int			is_in_string(char c, char *str);

//split functions
void	freememory(char **mem);
int		wordlen(char const *s, char c);
int		ft_wordcount(char const *s, char c);
char	**fill(char **split, char const *s, char c);
char	**ft_split(char const *s, char c);


//push_swap moves 
void	ft_sa_or_sb(t_array *array, char stack, int type);
void	shift_to_top(int *array, int used_size);
void    clear_top(int *array, int used_size);
void	ft_ss(t_stacks *stack, int type);
void    rotate_a(t_array *stack_a, int type);
void    rotate_b(t_array *stack_b, int type);
void	rotate_both(t_stacks *stacks, int type);
void    reverse_rotate_a(t_array *stack_a, int type);
void    reverse_rotate_b(t_array *stack_b, int type);
void    reverse_rotate_both(t_stacks *stacks, int type);

//stacks functions
char	**ft_stacks_init(char *string, t_stacks *stacks);
char	*ft_arg_to_string(char **av);
t_stacks	ft_create_stack(char *str);


//Cheking args and errors
int		count_numbers(char  *str);
int 	check_duplicates(t_stacks *stacks, int number);
int 	check_number(char *number);
int 	check_if_sorted(t_array *array);


//exit functions
int   		exit_error(void);
void 		free_stack(t_stacks *stacks, char *message);


//get_next_line functions
void	ft_bzero(void *s, size_t n);
char	*get_next_line(int fd);

#endif