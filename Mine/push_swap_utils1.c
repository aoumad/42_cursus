//
// Created by abder on 04/03/2022.
//

#include "push_swap.h"

void	ft_putendl_fd(char *s, int fd)
{
    int	i;

    i = 0;
    if (s != 0 && fd != 0)
    {
        while (s[i] != '\0')
        {
            write(fd, &s[i], 1);
            i++;
        }
        write(fd, "\n", 1);
    }
}

int	ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int     ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 || *s2)
    {
        if (*s1 != *s2)
            return ((unsigned char)*s1 - (unsigned char)*s2);
        s1++;
        s2++;
    }
    return (0);
}

size_t      ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char    *ft_strdup(const char *s)
{
    char    *copy;
    size_t  i;

    if (!(copy = malloc(sizeof(char) * ft_strlen(s) + 1)))
        return (NULL);
    i = 0;
    while (s[i] != '\0')
    {
        copy[i] = s[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}