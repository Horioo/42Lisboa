/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:40:01 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/04/04 18:07:57 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

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
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		error_msg("Error on dup fd[1]");
	close(fd[0]);
	execve_aux(av[2], envp);
}

void	parent_process(char **av, char **envp, int *fd)
{
	int		output_fd;

	output_fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (output_fd == -1)
		error_msg("Error on av[4]");
	if (dup2(fd[0], STDIN_FILENO) < 0)
		error_msg("Error on dup fd[0]");
	if (dup2(output_fd, STDOUT_FILENO) < 0)
		error_msg("Error on dup Output_fd");
	close(fd[1]);
	execve_aux(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (ac != 5)
		error_msg("Error on Arguments");
	if (pipe(fd) == -1)
		error_msg("Error on Pipe");
	pid1 = fork();
	if (pid1 == -1)
		error_msg("Error on Fork");
	if (pid1 == 0)
		child_process(av, envp, fd);
	close(fd[0]);
	close(fd[1]);
	// waitpid(-1, NULL, 0);
	// wait(0);
	//Atualizar para fazer 2 child process em vez de 1 child e um parent
	//Cada Child Process ira fazer 1 comando
	parent_process(av, envp, fd);
}
