/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:01:31 by aoumad            #+#    #+#             */
/*   Updated: 2022/03/10 11:01:31 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int   exit_error(void)
{
   ft_putendl_fd("Error", 1);
   exit (1);
}

void  free_stack(t_stacks *stacks, char *message)
{
   if (stacks)
   {
      if (stacks->stack_a.array)
         free(stacks->stack_a.array);
      if (stacks->stack_b.array)
         free(stacks->stack_b.array);
   }
   if (message != NULL)
      exit_error();
}