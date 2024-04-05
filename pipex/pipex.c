/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:40:01 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/04/05 18:29:18 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

void	free_commands(char **commands)
{
	int	i;

	i = -1;
	while (commands[++i])
		free(commands[i]);
	free(commands);
	error_msg("Error on Command/Path");
}

void	child_process(char **av, char **envp, int *fd)
{
	int	input_fd;

	input_fd = open(av[1], O_RDONLY);
	if (input_fd == -1)
	{
		close(fd[0]);
		close(fd[1]);
		error_msg("Error on av[1]");
	}
	if (dup2(input_fd, STDIN_FILENO) < 0)
		error_msg("Error on dup input_fd");
	close(input_fd);
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		error_msg("Error on dup fd[1]");
	close(fd[0]);
	close(fd[1]);
	execve_aux(av[2], envp);
}

void	child_process2(char **av, char **envp, int *fd)
{
	int		output_fd;

	output_fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (output_fd == -1)
		error_msg("Error on av[4]");
	if (dup2(fd[0], STDIN_FILENO) < 0)
		error_msg("Error on dup fd[0]");
	if (dup2(output_fd, STDOUT_FILENO) < 0)
		error_msg("Error on dup Output_fd");
	close(output_fd);
	close(fd[1]);
	close(fd[0]);
	execve_aux(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (ac != 5)
		error_msg("Error on Arguments");
	if (pipe(fd) == -1)
		error_msg("Error on Pipe");
	pid1 = fork();
	if (pid1 == -1)
		error_msg("Error on Fork");
	if (pid1 == 0)
		child_process(av, envp, fd);
	pid2 = fork();
	if (pid2 == 0)
		child_process2(av, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
