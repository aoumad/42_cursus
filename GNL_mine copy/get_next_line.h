/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:33:31 by aoumad            #+#    #+#             */
/*   Updated: 2022/01/02 18:40:49 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *leftxt, char *buff);
char	*get_next_line(int fd);
char	*ft_leftxt_remainder(char *leftxt);
char	*ft_get_line(char	*leftxt);
char	*ft_read_leftxt(int fd, char *leftxt);

#endif
