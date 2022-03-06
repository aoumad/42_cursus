//
// Created by abder on 04/03/2022.
//

#include "push_swap.h"

int check_number(char *number)
{
    int i;

    i = 0;
    if (number[i] == '-')
        i++;
    while (number[i])
    {
        if (!ft_isdigit(number[i]))
            return (0);
        i++;
    }
    return (1);
}

int check_duplicates(int argc,char *number)
{
    int     i;
    int     j;
    char    *dup;

    i = 0;
    while (argv[i])
    {
        dup = ft_strdup(argv[i]);
        j = 0;
        while (argv[j])
        {
            if (j == i)
                j++;
            else if (ft_strcmp(dup, av[j]))
            {
                // free the address of dup.
                // send message tells "Error! duplicated values".
            }
            else
                j++;
        }
        // free the address of dup
        i++;
    }
}

// a function to check overflow
// a function to check if arrays were sorted properly