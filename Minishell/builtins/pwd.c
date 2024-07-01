/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:07:57 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/07/01 16:11:11 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	builtin_pwd(t_cmd *cmd)
{
	char cwd[PATH_MAX];

	if(cmd->cmd[1])
	{
		write(2, "Cant use Args\n", 15);
		return ;
	}
	if(getcwd(cwd, PATH_MAX) != NULL)
		printf("%s\n", cwd);
	else
	{
		perror("Error getting current directory");
		return ;
	}
}