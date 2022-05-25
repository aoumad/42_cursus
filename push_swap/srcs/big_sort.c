/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:56:47 by aoumad            #+#    #+#             */
/*   Updated: 2022/05/21 01:02:15 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void    big_sort(t_stacks *stacks)
{
    int min;
    int index_min;

    numbers_sorted(stacks);
    awareness_of_sorted_nbr(stacks);
    push_numbers_non_sorted(stacks);
//     int j = 0;
//     while (j < stacks->stack_a.used_size)
//     {
//          printf("%d\n", stacks->stack_a.array[j]);
//          j++;
//     }
//   sleep(2);
    push_the_best_nbr(stacks);
    min = get_min(stacks->stack_a.array, stacks->stack_a.size);
    index_min = get_index(stacks->stack_a.array, min, stacks->stack_a.size);
    while (min != stacks->stack_a.array[0])
    {
        if (index_min >= stacks->stack_a.size / 2)
            reverse_rotate_a(&stacks->stack_a, ON);
        else
            ft_rotate_a(&stacks->stack_a, ON);
    }
    //     int j = 0;
    //     while (j < stacks->stack_a.used_size)
    // {
    //     printf("%d\n", stacks->stack_a.array[j]);
    //     j++;
    // }
}

/*void    numbers_sorted(t_stacks *stacks)
{
    int i;
    int j;
    int c;
    
    i = 0;
    if (!stacks->stack_a.t)
        exit(ft_err_and_free(stacks, "Error", 1));
    while (i < stacks->stack_a.used_size - 1)
    {
        j = i;
        c = 1;
        while (j < stacks->stack_a.used_size - 1)
        {
            if (stacks->stack_a.array[j] > stacks->stack_a.array[j + 1])
                break;
            c++;
            j++;
        }
        stacks->stack_a.t[i] = c;
        i++;
    }
}*/

void	numbers_sorted(t_stacks *stacks)
{
	int	i;
	int	j;
	int	k;
	int	r;
	int	c;

	i = 0;
	r = -1;
	c = 1;
    if (!stacks->stack_a.t)
        exit(ft_err_and_free(stacks, "Error", 1));
	while (i < stacks->stack_a.size)
	{
		j = i + 1;
		k = i;
		while (++r < stacks->stack_a.size - 1)
		{
			largest_numbers(stacks, &k, &j, &c);
			j++;
		}
		stacks->stack_a.t[i] = c;
		c = 1;
		r = -1;
        i++;
	}
}

// void    awareness_of_sorted_nbr(t_stacks *stacks)
// {
//     int i;
//     int j;
//     int head;
//     int r;
    
//     r = 0;
//     head = get_index(stacks->stack_a.t, get_max(stacks->stack_a.t,
//             stacks->stack_a.size), stacks->stack_a.size);
//             // printf("the max %d\n",head);
//             // sleep(2);
//     while (r < stacks->stack_a.size)
//         stacks->stack_a.t[r++] = 0;
//     r = 0;
//     i = head;
//     stacks->stack_a.t[i] = 1;
//     while (r < stacks->stack_a.size)
//     {
//         j = (i + 1) % stacks->stack_a.size;
//         if (stacks->stack_a.array[i] < stacks->stack_a.array[j])
//         {
//             stacks->stack_a.t[i] = 1;
//         }
//         else 
//             stacks->stack_a.t[i] = 0;
//         i++;
//         r++;
//     }
//         j = 0;

// }

void    awareness_of_sorted_nbr(t_stacks *stacks)
{
	int	head;
	int	r;
	int	k;
	int	i;
	int	j;

    head = get_index(stacks->stack_a.t, get_max(stacks->stack_a.t,
            stacks->stack_a.size), stacks->stack_a.size);
	r = -1;
	k = head;
	i = 0;
	while (i < stacks->stack_a.used_size)
		stacks->stack_a.t[i++] = 0;
	j = k;
	stacks->stack_a.t[k] = 1;
	while (++r < stacks->stack_a.used_size - 1)
	{
		if (stacks->stack_a.array[k] < stacks->stack_a.array[++j])
		{
			k = j;
			stacks->stack_a.t[k] = 1;
		}
		if (j == stacks->stack_a.used_size - 1)
			j = -1;
	}
    // j = 0;
    // while (j < stacks->stack_a.used_size)
    // {
    //      printf("%d---> %d\n", stacks->stack_a.array[j], stacks->stack_a.t[j]);
    //      j++;
    // }
    // sleep(2);
}

/*void    push_numbers_non_sorted(t_stacks *stacks)
{
    int j;
    int tmp;
    int tmp_2;
    
    j = 0;
    while (j < stacks->stack_a.size)
    {
        tmp = stacks->stack_a.array[j];
        if (stacks->stack_a.t[j] == 0)
        {
            while (stacks->stack_a.array[0] != tmp)
            {
                //printf("%d, %d\n", stacks->stack_a.array[0], tmp);
                if (j >= (stacks->stack_a.size / 2))
                    reverse_rotate_a(&stacks->stack_a, ON);
                else
                    ft_rotate_a(&stacks->stack_a, ON); 
            }
            //printf("---------------------> %d, %d\n", stacks->stack_a.array[0], tmp);
            ft_pb(stacks, ON);
        }
        j++;
    }
}*/

void    push_numbers_non_sorted(t_stacks *stacks)
{
    int j;
    int i;
    int tmp;
    int tmp_2;
    
    j = 0;
    i = 0;
    while (j < stacks->stack_a.size)
    {
        tmp = stacks->stack_a.array[i];
        if (i + 1 >= stacks->stack_a.size)
            tmp_2 = stacks->stack_a.array[0];
        else
            tmp_2 = stacks->stack_a.array[i + 1];
        find_non_sorted_numbers(stacks, tmp, i, j);
        i = get_index(stacks->stack_a.array, tmp_2, stacks->stack_a.size);
        j++;
    }
    free(stacks->stack_a.t);
}

void    push_the_best_nbr(t_stacks *stacks)
{
    int j;
    int min;
    int tmp_a;
    int tmp_b;
		// min = get_index(data->p, get_min(data->p, data->size_b), data->size_b);
		// j = get_index(data->stack_a, sml_max(data, data->stack_b[min]),
    while (stacks->stack_b.used_size)
    {
        calcul(stacks); // return array of t[i] --> stack_b.t[i] = c
        min = get_index(stacks->stack_b.t, get_min(stacks->stack_b.t,
                stacks->stack_b.used_size), stacks->stack_b.used_size);
        j = get_index(stacks->stack_a.array, small_max(stacks,
                stacks->stack_b.array[min]), stacks->stack_a.used_size);

        tmp_b = stacks->stack_b.array[min];
        tmp_a = stacks->stack_a.array[j];
        rotate_reverse_a_b(stacks, tmp_b, tmp_a, j);
        rotate(stacks, tmp_b, tmp_a, j);
        ft_pa(stacks, ON);
        free(stacks->stack_b.t);
    }

}

/*void    rotate_reverse_a_b(t_stacks *stacks, int tmp_b, int tmp_a, int j)
{
    int min;

    min = get_index(stacks->stack_b.t, get_min(stacks->stack_b.t,
            stacks->stack_b.size), stacks->stack_b.size);
    // daba khasni nbda rotate ad reverse rotate numbers 7ta nti7
    // f tmp_a && tmp_b li7sbt
    while (tmp_a != stacks->stack_a.array[0] &&
            tmp_b != stacks->stack_b.array[0])
    {
        if (j >= stacks->stack_a.used_size / 2 && min >= stacks->stack_b.used_size / 2)
            ft_rra_and_rrb(stacks, ON);
        else if (j <= stacks->stack_a.used_size / 2 &&
            min <= stacks->stack_b.used_size / 2)
            ft_ra_and_rb(stacks, ON);
        else
            break; // wslti am3lm l tmp_a o tmp_b
    }
}*/

void printfstacks(t_stacks *stacks)
{
    int i;
    
    i = 0;
    printf("stack a is here: \n");
    while (i < stacks->stack_a.used_size)
    {
        printf("%d ----> %d\n", i, stacks->stack_a.array[i]);
        i++;
    }
    int j = 0;
    printf("----------------------------\n");
    printf("stack b is here: \n");
    while (j < stacks->stack_b.used_size)
    {
        printf("%d ----> %d\n",j, stacks->stack_b.array[j]);
        j++;
    }
}

void    rotate_reverse_a_b(t_stacks *stacks, int tmp_b, int tmp_a, int j)
{
	int	min;

	min = get_index(stacks->stack_b.t, get_min(stacks->stack_b.t, stacks->stack_b.used_size), stacks->stack_b.used_size);
    // printf("the size is %d\n", stacks->stack_b.used_size);
    // printf("the min is %d\n",min);
    // printfstacks(stacks);
    // sleep(2);
	while (tmp_a != stacks->stack_a.array[0] && tmp_b != stacks->stack_b.array[0])
	{
		if (j >= stacks->stack_a.used_size / 2 && min >= stacks->stack_b.used_size / 2)
			ft_rra_and_rrb(stacks, ON);
		else if (j <= stacks->stack_a.used_size / 2 && min <= stacks->stack_b.used_size / 2)
			ft_ra_and_rb(stacks, ON);
		else
			break ;
	}
}

void    rotate(t_stacks *stacks, int tmp_b, int tmp_a, int j)
{
    int min;

    min = get_index(stacks->stack_b.t, get_min(stacks->stack_b.t,
            stacks->stack_b.used_size), stacks->stack_b.used_size);
    while (tmp_a != stacks->stack_a.array[0])
    {
        if (j >= stacks->stack_a.used_size / 2)
        {
            //  printf("nta hna\n");
            reverse_rotate_a(&stacks->stack_a, ON);
        }

        else
        {
            //printf("nta hna\n");
            ft_rotate_a(&stacks->stack_a, ON);
        }
          
    }
   // (void)tmp_b;
   while (tmp_b != stacks->stack_b.array[0])
    {
        if (min >= stacks->stack_b.used_size / 2)
        {
            //printf("nta hna\n");
            reverse_rotate_b(&stacks->stack_b, ON);
        }
        else
            ft_rotate_b(&stacks->stack_b, ON);
    }
}

void    find_non_sorted_numbers(t_stacks *stacks, int tmp, int i, int j)
{
    if (stacks->stack_a.t[j] == 0)
    {
        while (stacks->stack_a.array[0] != tmp)
        {
            if (i >= (stacks->stack_a.size / 2))
               reverse_rotate_a(&stacks->stack_a, ON);
            else
            {
                //printf("nta hna\n");
                ft_rotate_a(&stacks->stack_a, ON);
            }
        }
        ft_pb(stacks, ON);
    }
}