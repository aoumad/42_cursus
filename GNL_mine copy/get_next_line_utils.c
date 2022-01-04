/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 11:26:47 by aoumad            #+#    #+#             */
/*   Updated: 2022/01/03 18:22:15 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char )c)
			return ((char *)s);
		s++;
	}
	if ((char )c == 0)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *leftxt, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!leftxt)
	{
		leftxt = (char *)malloc(1 * sizeof(char));
		leftxt[0] = 0;
	}
	if (!leftxt || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(leftxt) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (leftxt[++i] != 0)
		str[i] = leftxt[i];
	while (buff[j] != 0)
		str[i++] = buff[j++];
	str[ft_strlen(leftxt) + ft_strlen(buff)] = 0;
	free(leftxt);
	return (str);
}
