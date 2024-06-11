/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:11:10 by luiberna          #+#    #+#             */
/*   Updated: 2024/06/11 17:44:09 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void handle_n(char **cmd, int pos)
{
	int j;

	j = 0;
	while(cmd[j])
		j++;
	while(cmd[pos])
	{
		if(pos + 1 == j)
			printf("%s", cmd[pos]);
		else
			printf("%s ", cmd[pos]);
		pos++;
	}
}

void	builtin_echo(char **cmd)
{
	int n_flag;

	
	n_flag = 0;
	if(cmd[1] && ft_strncmp(cmd[1], "-n", 2))
		n_flag = 1;
	if(n_flag == 1)
		handle_n(cmd, 2);
	else
	{
		handle_n(cmd, 1);
		printf("\n");
	}	
}

///////////////////////////////////////////////////////////////////////////////////

void	builtin_pwd(void)
{
	char cwd[PATH_MAX];

	if(getcwd(cwd, PATH_MAX) != NULL)
		printf("%s\n", cwd);
	else
	{
		perror("Error getting current directory");
		return ;
	}
}

///////////////////////////////////////////////////////////////////////////////////

void	builtin_env(t_amb *env)
{
	int i;

	i = 0;
	if(!env->envp && !env->envp[0])
		perror("Error on env");
	while(env->envp[i])
	{
		if(ft_strchr(env->envp[i], '='))
			printf("%s\n", env->envp[i]);
		i++;
	}
}

///////////////////////////////////////////////////////////////////////////////////

int		ft_isnumber(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void ignore_space_set_sign(char *str, int *i, int *sign)
{
	while(str[*i] && str[*i] == ' ')
		(*i)++;
	if(str[*i] && (str[*i] == '-' || str[*i] == '+'))
	{
		if(str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

int		exit_atoi(char *str)
{
	int i;
	int sign;
	unsigned long res;
	int e_status;
	
	sign = 1;
	i = 0;
	res = 0;
	ignore_space_set_sign(str, &i, &sign);
	if(!ft_isnumber(str + i))
	{
		e_status = //Print_err - Mensagem de erro (bash: exit: (string): numeric argument required) / exit: (number) = cmd[0] e cmd[1]
		//Limpar o Minishell e depois exit com a status_exit
	}
	while(str[i])
	{
		res = res * 10 + (str[i] + '0');
		if(res > LONG_MAX)
		{
			e_status = //Print_err - Mensagem de erro (bash: exit: (number): numeric argument required) / exit: (number) = cmd[0] e cmd[1]
			//Limpar o Minishell e depois exit com a status_exit
		}
		i++;
	}
	return((res * sign) % 256);
}

void	builtin_exit(char **cmd)
{
	int e_status;

	
	if(cmd[0])
	{
		if(cmd[1] && ft_isnumber(cmd[1]))
		{
			e_status = //Print_err - Mensagem de erro (bash: exit: too many arguments)
			//Limpar o Minishell e depois exit com a status_exit
		}
		else
			e_status = exit_atoi(cmd[0]);
	}
	clean_minishell();
	exit(e_status);
}

