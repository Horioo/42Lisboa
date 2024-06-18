/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:23:52 by luiberna          #+#    #+#             */
/*   Updated: 2024/06/18 15:23:22 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_matrix(char **mtx)
{
	int i = 0;
	while(mtx[i])
	{
		int j = 0;
		printf("mtx[%d] = ", i);
		while(mtx[i][j])
		{
			printf("%c", mtx[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
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
		print_matrix(cmd->cmd);
        //pipes_exec(cmd, env);
        //check_cmd(cmd, env->envp);
		builtin_unset(env, cmd);
		builtin_export(env, cmd);
        free(input);
    }
    return (0);
}
