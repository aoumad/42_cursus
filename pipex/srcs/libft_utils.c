/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 03:46:40 by aoumad            #+#    #+#             */
/*   Updated: 2022/04/19 15:48:41 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;

	j = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[j] && j < len)
	{
		if (haystack[j] == needle[0])
		{
			i = 0;
			while (haystack[j + i] == needle[i]
				&& haystack[j + i]
				&& j + i < len)
				i++;
			if (j + i > len)
				return (NULL);
			if (!needle[i])
				return ((char *)(haystack + j));
		}
		j++;
	}
	return (NULL);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
		write(fd, s++, 1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s;
	unsigned int	i;

	if (!s1 || !s2)
		return (NULL);
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (*s1)
		s[i++] = *(s1++);
	while (*s2)
		s[i++] = *(s2++);
	s[i] = 0;
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;
	size_t			len_str;

	if (!s)
		return (NULL);
	len_str = ft_strlen(s);
	if (start >= len_str)
		len = 0;
	else if (len > len_str)
		len = len_str;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = -1;
	while (++i < len && s[i])
		substr[i] = s[i + start];
	substr[i] = 0;
	return (substr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
