/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:23:52 by luiberna          #+#    #+#             */
/*   Updated: 2024/06/26 15:55:47 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	if (ft_strncmp(cmd, "cd", 3) == 0)
        return 1;
    else if (ft_strncmp(cmd, "pwd", 4) == 0)
        return 1;
    else if (ft_strncmp(cmd, "echo", 5) == 0)
        return 1;
    else if (ft_strncmp(cmd, "export", 8) == 0)
        return 1;
    else if (ft_strncmp(cmd, "unset", 7) == 0)
        return 1;
    else if (ft_strncmp(cmd, "env", 4) == 0)
        return 1;
    else if (ft_strncmp(cmd, "exit", 5) == 0)
        return 1;
	return 0;
}

int main (int argc, char **argv, char **envp)
{
    char *input;
    t_cmd *cmd;
    t_env *env;
    int i = 0;

    if (argc != 1)
        return (ft_printf("Minishell takes no args\n"), 0);
    env = get_env(envp);
    (void)argv;
    while (1) 
    {
        input = readline("DrunkShell \U0001F37A> ");
        add_history(input);
        cmd = lexer_args(input, env->envp);
        if (cmd)
        {
			if(is_builtin(cmd->cmd[i]))
				execute(cmd, env);
			else
            	pipes_exec(cmd, env);
            free(input);
        }
        //check_cmd(cmd, env->envp);
    }
    return (0);
}
