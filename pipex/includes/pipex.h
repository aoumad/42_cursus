/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 08:30:37 by aoumad            #+#    #+#             */
/*   Updated: 2022/04/19 15:53:10 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>

void	error(void);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);
void	child_process(char **argv, char **envp, int *fd);
void	parent_process(char **argv, char **envp, int *fd);
int		main(int argc, char **argv, char **envp);

void	ft_putstr_fd(char *s, int fd);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

void	freememory(char **mem);
int		wordlen(char const *s, char c);
int		ft_wordcount(char const *s, char c);
char	**fill(char **split, char const *s, char c);
char	**ft_split(char const *s, char c);

#endif
