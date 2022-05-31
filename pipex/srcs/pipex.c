/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 08:30:34 by aoumad            #+#    #+#             */
/*   Updated: 2022/04/19 15:52:27 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process( char **argv, char **envp, int *fd)
{
	int	file_in;

	close(fd[0]);
	file_in = open(argv[1], O_RDONLY, 0777);
	if (file_in == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(file_in, STDIN_FILENO);
	close(fd[1]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	file_out;

	close(fd[1]);
	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_out == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(fd[0]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child_process(argv, envp, fd);
		parent_process(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("Error: Bad arguments\n", 2);
		ft_putstr_fd("EX : ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}
