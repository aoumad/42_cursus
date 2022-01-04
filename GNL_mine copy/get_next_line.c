/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:37:47 by aoumad            #+#    #+#             */
/*   Updated: 2022/01/04 09:11:18 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_leftxt(int fd, char *leftxt)
{
	char	*buffer;
	int		sz;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	sz = 1;
	while (!ft_strchr(leftxt, '\n') && sz > 0)
	{
		sz = read(fd, buffer, BUFFER_SIZE);
		if (sz == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[sz] = 0;
		leftxt = ft_strjoin(leftxt, buffer);
	}
	free(buffer);
	return (leftxt);
}

char	*ft_get_line(char	*leftxt)
{
	int		i;
	char	*str;

	i = 0;
	if (!leftxt[i])
		return (NULL);
	while (leftxt[i] && leftxt[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (leftxt[i] && leftxt[i] != '\n')
	{
		str[i] = leftxt[i];
		i++;
	}
	if (leftxt[i] == '\n')
		str[i++] = '\n';
	str[i] = 0;
	return (str);
}

char	*ft_leftxt_remainder(char *leftxt)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (leftxt[i] && leftxt[i] != '\n')
		i++;
	if (!leftxt[i])
	{
		free(leftxt);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(leftxt) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (leftxt[i])
		str[j++] = leftxt[i++];
	str[j] = 0;
	free (leftxt);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*leftxt;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	leftxt = ft_read_leftxt(fd, leftxt);
	if (!leftxt)
		return (NULL);
	line = ft_get_line(leftxt);
	leftxt = ft_leftxt_remainder(leftxt);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}*/

#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	int		fd;
	char	*str;

	fd = open("test_no_nl.txt", O_RDONLY);
		str = get_next_line(fd);
		printf("%s",str);
	close (fd);
	return (0);
}
