/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:27:52 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/04/05 18:29:13 by ajorge-p         ###   ########.fr       */
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

int	is_path(char *cmd)
{
	if (cmd[0] == '/' && (access(cmd, F_OK) == 0))
		return (1);
	else
		return (0);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*slashed_path;
	char	*cmd_path;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0 && cmd)
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
	if(!commands || !commands[0])
		free_commands(commands);
	if (is_path(cmd))
		path = ft_strdup(cmd);
	else
	{
		path = find_path(commands[0], envp);
		if (!path)
			free_commands(commands);
	}
	if (execve(path, commands, envp) == -1)
		error_msg("Error on execve");
}
