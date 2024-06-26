/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:11:10 by luiberna          #+#    #+#             */
/*   Updated: 2024/06/26 15:52:58 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

///////////////////////////////////////////////////////////////////////////////////

/*Echo Builtin*/

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
	if(cmd[1] && ft_strncmp(cmd[1], "-n", 2) == 0)
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

/*PWD Builtin*/

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

///////////////////////////////////////////////////////////////////////////////////

/*ENV Builtin*/

void	builtin_env(t_env *env)
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

/*Exit Builtin*/

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

typedef enum e_err_msg
{
	CMD_NOT_FOUND,
	NO_FILE,
	PERM_DENIED,
	AMBIGOUS_MSG,
	TOO_MANY_ARGS,
	NUM_REQUIRED,
} err_msg;

typedef struct t_error
{
	err_msg type;
	char *msg;
} s_error;


//Precisei de mudar o tipo da funcao ft_putstr_fd para int devido aos returns

int		print_err(s_error err)
{
	if(err.type == CMD_NOT_FOUND)
		return(ft_putstr_fd(err.msg, 2), ft_putstr_fd(": command not found\n", 2));
	else if (err.type == NO_FILE)
		return(ft_putstr_fd(err.msg, 2), ft_putstr_fd(": No such file or directory\n", 2));
	else if (err.type == PERM_DENIED)
		return(ft_putstr_fd(err.msg, 2), ft_putstr_fd(": Permission denied\n", 2));
	else if (err.type == AMBIGOUS_MSG)
		return(ft_putstr_fd("minishell: ", 2), ft_putstr_fd(err.msg, 2), ft_putstr_fd(" ambiguous redirect\n", 2));
	else if(err.type == TOO_MANY_ARGS)
		return(ft_putstr_fd("minishell: ", 2), ft_putstr_fd(err.msg, 2), ft_putstr_fd(" too many arguments\n", 2));
	else if(err.type == NUM_REQUIRED)
		return(ft_putstr_fd("minishell: ", 2), ft_putstr_fd(err.msg, 2), ft_putstr_fd(" numeric argument required\n", 2));
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

int		exit_atoi(t_cmd *ms, char *str)
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
		e_status = print_err((s_error){NUM_REQUIRED, str});
		(free_cmd(ms), exit(e_status));
	}
	while(str[i])
	{
		res = res * 10 + (str[i] + '0');
		if(res > LONG_MAX)
		{
			e_status = print_err((s_error){NUM_REQUIRED, str});
			(free_cmd(ms), exit(e_status));
		}
		i++;
	}
	return((res * sign) % 256);
}

void	builtin_exit(t_cmd *ms, char **cmd)
{
	int e_status;

	printf("Entrou\n");
	e_status = 0;
	if(cmd[0])
	{
		if(cmd[1] && !ft_isnumber(cmd[1]))
		{
			e_status = print_err((s_error){TOO_MANY_ARGS, cmd[1]});
			(free_cmd(ms), exit(e_status));
		}
		else if(cmd[1])
			e_status = exit_atoi(ms, cmd[1]);
	}
	printf("Chegou 1\n");
	free_cmd(ms);
	printf("Chegou 2\n");
	exit(e_status);
}

///////////////////////////////////////////////////////////////////////////////////

/*Export Builtin*/

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

int find_eq(char *str) {
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
	printf("value = %s\n", value);
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

///////////////////////////////////////////////////////////////////////////////////

/* Unset Builtin*/

void	unset(t_env *env, char *cmd)
{
	int i;
	int eq;

	i = 0;
	if(env->envp && env->envp[i])
	{
		eq = find_eq(env->envp[i]);
		while(env->envp[i] && ft_strncmp(cmd, env->envp[i], eq))
		{
			i++;
			eq = find_eq(env->envp[i]);
		}
		free(env->envp[i]);
		env->envp[i] = env->envp[i + 1];
		i++;
		while(env->envp[i])
		{
			env->envp[i] = env->envp[i + 1];
			i++;
		}
		env->envp[i] = NULL;
	}
}

void	builtin_unset(t_env *env, t_cmd *cmd)
{
	int i;

	if(!cmd->cmd[1])
		return ;
	else
	{
		i = 1;
		while(cmd->cmd && cmd->cmd[i])
		{
			if(error_handler(cmd->cmd[i]))
				export_error(cmd, i, cmd->cmd);
			unset(env, cmd->cmd[i]);
			i++;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////

/*CD BUILTIN*/

int	command_len(char **cmd)
{
	int i;

	i = 0;
	while(cmd && cmd[i])
		i++;
	return (i);	
}

char *find_on_env(char **env, char *tofind)
{
	int i;
	char *ret;

	i = 0;
	while(env[i])
	{
		if(ft_strncmp(env[i], tofind, ft_strlen(tofind)) == 0)
		{
			ret = ft_strdup(env[i] + ft_strlen(tofind) + 1);
			return (ret);
		}
		i++;
	}
	return (NULL);
}

int save_pwd(char *var_to_update, t_env *env)
{
	char var[PATH_MAX];
	int i;
	char *tmp;

	i = 0;
	if(getcwd(var, sizeof(var)))
	{
		while(env->envp[i] && ft_strncmp(env->envp[i], var_to_update, ft_strlen(var_to_update)) != 0)
			i++;
		if(env->envp[i])
			free(env->envp[i]);
		env->envp[i] = ft_strdup(var_to_update);
		tmp = ft_strjoin("=", var);
		env->envp[i] = ft_strjoin(env->envp[i], tmp);
		free (tmp);
	}	
	return (1);
}

// Necessario atualizar o PWD e guardar um OLDPWD para o caso de apagarem a pasta onde estavamos a a executar o minishell
int	exec_cd(char *path, t_env *env)
{
	save_pwd("OLDPWD", env);
	printf("path = %s\n", path);
	if(chdir(path) == 0 && save_pwd("PWD", env))
		//Update Global Status para 0
		printf("CD Efetucado\n");
	else
	{
		if(access(path, F_OK) == -1)
			write(2, "minishell: cd: no such file or directory\n", 42);
		else if(access(path, R_OK | W_OK | X_OK) == -1)
			write(2, "minishell: cd: Permission denied\n", 34);
		else
			write(2,"minishell: cd: not a directory\n", 32);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		//Update Global status para 1
	}
	return (1);
}

// Casos possiveis no CD - "cd" / "cd --" / "cd -" / "cd path"

void	builtin_cd(t_env *env, t_cmd *cmd)
{
	char *home_path;
	if(command_len(cmd->cmd) > 2)
	{
		write(2, "Minishell: cd: too many arguments\n", 35);
		//Update Global status para 1 
		return ;
	}
	home_path = find_on_env(env->envp, "HOME");
	home_path = ft_strjoin(home_path, "/");
	if(!cmd->cmd[1] && exec_cd(home_path, env))
		//Update Global Status para 0 e Voltar para tras
		return ;
	else
	{
		if(ft_strcmp(cmd->cmd[1], "--") == 0 && exec_cd(home_path, env))
			//Update Global Status para 0 e Voltar para tras
			return ;
		exec_cd(cmd->cmd[1], env);
	}
}