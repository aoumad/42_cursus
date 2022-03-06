//
// Created by abder on 05/03/2022.
//

#include "push_swap.h"
//using it for reverse rotate instruction
void    clear_top(int *array, int used_size)
{
    while (used_size > 0)
    {
        array[used_size] = array[used_size - 1];
        used_size--;
    }
}
//Using it for rotate instruction
void    shift_to_top(int *array, int used_size)
{
    int i;

    i = 0;
    while (i < used_size)
    {
       array[i] = array[i + 1];
       i++;
    }
}