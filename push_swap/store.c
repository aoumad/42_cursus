#include "push_swap.h"

/*char	*ft_arg_to_string(char **av)
{
	char	*string;
	char	*tmp;
	int		i;

	i = 1;
	string = (char *)malloc(1);
	while (av[i])
	{
		if (!ft_check_arg(av[i]))
			printf("Error");
		else
		{
			tmp = ft_strjoin(string, av[i]);
			free(string);
			string = ft_strjoin(tmp, " ");
			free(tmp);
			i++;
		}
	}
	return (string);
}*/

char    *transform_args(int argc, char **argv)
{
    char    *str = malloc(100 * 1);
    int     i;
    
    i = 1;
    while (i < argc - 1)
    {
        str[i] = ft_atoi(argv[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}

char    **init_stack(t_stacks *stacks, char *str)
{
    int     size;
    char    **numbers;
    
    size = count_numbers(str);
    numbers = ft_split(str, ' ');
    
    stacks->stack_a.array = (int *)malloc(sizeof(int) * size);
    stacks->stack_b.array = (int *)malloc(sizeof(int) * size);
    stacks->stack_a.size = size;
    stacks->stack_b.size = size;
    stacks->stack_a.used_size = 0;
    stacks->stack_b.used_size = 0;
    free(str);
    return (numbers);
}

t_stacks    create_stack(char   *str)
{
    t_stacks    stacks;
    int         number;
    char        **numbers;
    int         i;

    i = 0;
    
    numbers = init_stack(&stacks, str);
    while (numbers[i])
    {
        number = ft_atoi(numbers[i]);
        printf("HI");
        if (!check_duplicates(&stacks,number))
            printf("Error");
        stacks.stack_a.array[i] = number;
        stacks.stack_a.used_size++;
        //free(numbers[i]);
        i++;
    }
    printf("Hello");
    free(numbers);
    return (stacks);
}


