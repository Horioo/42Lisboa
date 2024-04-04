/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:27:52 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/04/04 15:37:45 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

void	error_msg(char *s)
{
	perror(s);
	exit(1);
}

void	free_paths(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*slashed_path;
	char	*cmd_path;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!i)
		return ("Error");
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		slashed_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(slashed_path, cmd);
		free(slashed_path);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	free_paths(paths);
	return (0);
}

void	execve_aux(char *cmd, char **envp)
{
	char	**commands;
	int		i;
	char	*path;
	int		status;

	i = -1;
	status = 0;
	commands = ft_split(cmd, ' ');
	path = find_path(commands[0], envp);
	if (!path)
	{
		while (commands[++i])
			free(commands[i]);
		free(commands);
		error_msg("Error on Command/Path");
	}
	if (execve(path, commands, envp) == -1)
		error_msg("Error on execve");
}
