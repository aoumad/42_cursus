/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:11:59 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/20 03:19:29 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ON 1
# define OFF 0

typedef struct array
{
    int size;
    int used_size;
    int *array;
    int *t;
}   t_array;

typedef struct stack
{
    t_array stack_a;
    t_array stack_b;
}   t_stacks;

char        *ft_arg_to_string(char **argv);
int         ft_check_arg(char *argv);
int         ft_err_and_free(t_stacks *stacks, char *message, int return_value);
t_stacks    ft_create_stack(char *str);
int         ft_count_numbers(char *string);
int         ft_check_number(char *number);
int         ft_check_duplicates(t_stacks *stacks, int number);
int         ft_check_sorted(t_array *array);
char	    **ft_stacks_init(char *string, t_stacks *stacks);

//====== libft =======//
int	        ft_isdigit(int c);
char        *ft_substr(char const *s, unsigned int start, size_t len);
size_t	    ft_strlen(const char *s);
long long	ft_atoi(const char *str);
char	    *ft_strjoin(char const *s1, char const *s2);

//===== split =====//
void	    freememory(char **mem);
int	        wordlen(char const *s, char c);
int	        ft_wordcount(char const *s, char c);
char	    **fill(char **split, char const *s, char c);
char	    **ft_split(char const *s, char c);

//===== big sorted ===//
void    big_sort(t_stacks *stacks);
void    numbers_sorted(t_stacks *stacks);
void    awareness_of_sorted_nbr(t_stacks *stacks);
void    push_the_best_nbr(t_stacks *stacks);
void    push_numbers_non_sorted(t_stacks *stacks);
void    rotate_reverse_a_b(t_stacks *stacks, int tmp_b, int tmp_a, int j);
void    rotate(t_stacks *stacks, int tmp_b, int tmp_a, int j);
void    find_non_sorted_numbers(t_stacks *stacks, int tmp, int i, int j);


//===== calcul_utils ====//
void    calcul(t_stacks *stacks);
void	calcul_rr_rrr(t_stacks *stacks, int i, int *c, int j);


//==== sort ====//
int     get_index(int *t, int a, int size);
void    largest_numbers(t_stacks *stacks, int *k, int *j, int *c);

//===== min_max ====//
int small_max(t_stacks *stacks, int nbr);
int get_min(int *t, int size);
int get_max(int *t, int size);

//==== moves ===//
void    ft_clear_first_elm(int *array, int used_size);
void    ft_remove_first_elm(int *array, int used_size);
void	ft_pa(t_stacks *stacks, int type);
void	ft_pb(t_stacks *stacks, int type);
void    reverse_rotate_a(t_array *stack_a, int type);
void    reverse_rotate_b(t_array *stack_b, int type);
void	ft_rra_and_rrb(t_stacks *stacks, int type);
void    ft_rotate_a(t_array *stack_a, int type);
void    ft_rotate_b(t_array *stack_b, int type);
void    ft_ra_and_rb(t_stacks *stacks, int type);
void    ft_sa_or_sb(t_array *array, int type, char stack);
void    ft_sa_and_sb(t_stacks *stacks, int type);

//==== sort 3 and 10 ====//
void	sort_3(t_stacks *stacks);
int     is_stack_a_sorted(t_stacks *stacks);
void    sort_10(t_stacks *stacks);

#endif