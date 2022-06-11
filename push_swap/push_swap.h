/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:55:05 by aoumad            #+#    #+#             */
/*   Updated: 2022/06/11 12:16:48 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_data
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	max_size;
	int	*temp;
	int	*temp2;
	int	*p;
	int	*t;
}	t_data;

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
int					get_min(int *t, int size);
int					get_max(int *t, int size);
void				sort_3(t_data *data);
int					is_sorted_stacka(t_data *data);
int					get_index(int *t, int a, int size);
void				sort_5(t_data *data);
int					ft_strcmp(char *s1, char *s2);
void				end(t_data *data);
int					rra(t_data *data);
int					rrb(t_data *data);
int					ra(t_data *data);
int					rb(t_data *data);
void				calcul_rr_rrr(t_data *data, int i, int *c, int j);
void				calcul(t_data *data);
void				largest_numbers(t_data *data, int *k, int *j, int *c);
void				find_number_nosorted(t_data *data, int temp, int i, int j);
void				rotate(t_data *data, int tempb, int tempa, int j);
int					sml_max(t_data *data, int nbr);
int					sb(t_data *data);
void				push_toa_best_number(t_data *data);
void				rotaterevab(t_data *data, int tempb, int tempa, int j);
void				push_numbers_notsorted(t_data *data);
void				get_numbers_sorted(t_data *data);
void				numbers_sorted(t_data *data);

#endif
