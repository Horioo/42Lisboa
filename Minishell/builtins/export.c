/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:07:53 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/07/01 16:33:34 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
			i++;
		return (s1[i] - s2[i]);
	}
	return (1);
}

int	size_of_env(char **env)
{
	int i;

	i = 0;
	while(env && env[i])
		i++;
	return (i);
}

void	sort_env(char **env, int size)
{
	int i;
	int swapping;
	char *tmp;
	swapping = 1;
	while(swapping)
	{
		i = 0;
		swapping = 0;
		while(i < size - 1)
		{
			if(ft_strcmp(env[i], env[i + 1]) > 0)
			{
				tmp = env[i];
				env[i] = env[i + 1];
				env[i + 1] = tmp;
				swapping = 1;
			}
			i++;
		}
		size--;
	}	
	
}

void	print_env(t_env *env)
{
	int	i;
	int j;
	int first_equal;
	i = 0;

	sort_env(env->envp, size_of_env(env->envp));
	while(env->envp[i])
	{
		printf("declare -x ");
		j = -1;
		first_equal = 1;
		while(env->envp[i][++j])
		{
			printf("%c", env->envp[i][j]);
			if(env->envp[i][j] == '=' && first_equal)
			{
				printf("\"");
				first_equal = 0;
			}
		}
		if(ft_strchr(env->envp[i], '='))
			printf("\"");
		printf("\n");
		i++;
	}
}


void	free_dp(char **var)
{
	int i;

	i = 0;
	while(var[i])
	{
		free(var[i]);
		i++;
	}
	free(var);
}

void	export_error(t_cmd *cmd, int i, char **str)
{
	write(2, "minishell: export: \'", 21);
	write(2, cmd->cmd[i], ft_strlen(cmd->cmd[i]));
	write(2, "\': not a valid identifier\n", 26);
	free_dp(str);
	exit(1);
	//Atualizar a global variable do status
}

int find_eq(char *str)
{
	int i; 

	i = -1;
	while (str[++i])
	 if (str[i] == '=')
	 	return (i);
	return (0);
}

char **handle_no_value(char *var, char **env)
{
	int i;

	i = 0;
	while(env && env[i])
	{
		if(!ft_strncmp(var, env[i], ft_strlen(var)))
			return (env);
		i++;
	}
	env[i] = ft_strdup(var);
	env[++i] = NULL;
	return (env);
}

//Vai fazer, se a var ja existir e o valor for igual
//Se a var ja existir e o valor for diferente
//Se a var nao existir
char **var_exists(char *var, char *value, char **env)
{
	int i;
	int ret;

	i = 0;
	if(!value)
		return (handle_no_value(var, env));
	while(env && env[i])
	{
		if(!ft_strncmp(var, env[i], ft_strlen(var)) && !ft_strcmp(value, env[i] + ft_strlen(var)))
			return env;
		else if(!ft_strncmp(var, env[i], ft_strlen(var)) && ft_strcmp(value, env[i] + ft_strlen(var))!= 0)
		{
			free(env[i]);
			env[i] = ft_strjoin(var, value);
			return env;	
		}
		i++;
	}
	env[i] = ft_strjoin(var, value);
	env[++i] = NULL;
	return (env);
}

void export(t_env *env, t_cmd *cmd, int i)
{
	int j;
	int eq;
	char *var;

	eq = find_eq(cmd->cmd[i]);
	if (eq == 0)
	{
		var = ft_strdup(cmd->cmd[i]);
		env->envp = var_exists(var, NULL, env->envp);
	}
	else
	{
		cmd->cmd[i][eq] = 0;
		var = ft_strdup(cmd->cmd[i]);
		cmd->cmd[i][eq] = '=';
		env->envp = var_exists(var, cmd->cmd[i] + eq, env->envp);
	}
	free(var);
}
//Search until Equal
int sue(char *str, char c)
{
	int i;

	i = 0;
	while(str && str[i] && str[i] != '=')
	{
		if(str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	error_handler(char *cmd)
{
	if(!cmd[0] || cmd[0] == '=' || (cmd[0] == '_' && cmd[1] == '=') || ft_isdigit(cmd[0]) || sue(cmd, '-') || sue(cmd, '.') || 
		sue(cmd, ':') || sue(cmd, ',') || sue(cmd, '\\') || sue(cmd, '!') || sue(cmd, '?'))
		return 1;
	return 0;
}

void	builtin_export(t_env *env, t_cmd *cmd)
{
	int i;

	if(!cmd->cmd[1])
	{
		print_env(env);
		return ;
	}
	i = 1;
	while(cmd->cmd && cmd->cmd[i])
	{
		if(error_handler(cmd->cmd[i]))
			export_error(cmd, i, cmd->cmd);
		export(env, cmd, i);
		i++;
	}
}