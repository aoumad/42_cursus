/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:01:39 by aoumad            #+#    #+#             */
/*   Updated: 2022/03/11 17:01:39 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*int main(int argc, char **argv)
{
    t_stacks  stacks;
    char      *string;

    argc--;
    if (argc == 0)
        return (0);
    string = ft_arg_to_string(argv);
    stacks = create_stack(string);;
	free_stack(&stacks, NULL);
    return (0);
}*/

int    main(int ac, char *av[])
{
    t_stacks stacks;
    //t_stack    *a;
    //t_stack    *b;
    
//     a = create_stack(ac);
//     if (ac == 1 ||(ac == 2 && ft_atoi(av[ac - 1], a)))
//         return (0);
//     push_check(a, ac, av);
//     b = create_stack(ac);
// //    printf("%i\n",-0007);
    stacks.stack_a = ft_create_stack("110");
    stacks.stack_b = ft_create_stack(110);
    push(-1,b);
    push(-2,b);
    push(-3,b);
    push(-4,b);
    
    push(1,a);
    push(2,a);
    push(3,a);
    push(4,a);
    
//    pa(a, b);
    pb (a, b);
    
    printf("%d\t",a->stack[a->top]);
    printf("%d\n",b->stack[b->top]);
    printf("%d\t",a->stack[a->top - 1]);
    printf("%d\n",b->stack[b->top - 1]);
    printf("%d\t",a->stack[a->top - 2]);
    printf("%d\n",b->stack[b->top - 2]);
//    printf("%d\t",a->stack[a->top - 3]);
//    printf("%d\t",a->stack[a->top - 4]);
    printf("%d\n",b->stack[b->top - 3]);
}