/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:23:52 by luiberna          #+#    #+#             */
/*   Updated: 2024/06/28 17:21:02 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		while (cmd->next != NULL)
    cmd = cmd->next;
while(cmd != NULL)
{
    i = 0;
    while (cmd->cmd[i])
    {
        printf("Comando numero:%i, Linha numero %i: %s\n",cmd->nb_cmds, i, cmd->cmd[i]);
        i++;
    }
    cmd = cmd->prev;
}
        // if (cmd)
        // {
        //     pipes_exec(cmd, env);
        //     free(input);
        // }
        //check_cmd(cmd, env->envp);
    }
    return (0);
}
