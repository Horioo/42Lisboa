/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:58:43 by luiberna          #+#    #+#             */
/*   Updated: 2024/07/01 16:34:54 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_env
{
    char **envp;
    struct s_env *next;
    struct s_env *prev;
}               t_env;

typedef struct s_cmd
{
    char **cmd;
    char *path;
    int fd[2];
    int fd_redirect[2];
    pid_t pid;
    int nb_cmds;
    struct s_cmd *next;
    struct s_cmd *prev;
}               t_cmd;

//env
t_env   *get_env(char **envp);

//exec
int    execute(t_cmd *cmd, t_env *env);

//free
void    free_list(char **list);
void    free_cmd(t_cmd *cmd);

//init
char	*get_path(char *cmd, char **envp);
t_cmd   *create_cmd(char *sep_cmd, t_cmd *prev_cmd, int i, char **envp);
t_cmd   *init_cmd(char *input, char **envp);

//parse
int     arglen(char *input);
t_cmd   *lexer_args(char *input, char **envp);

//pipes
void	close_fds(t_cmd *cmd);
void	error_msg(char *str);
void    execve_aux(t_cmd *cmd, t_env *env);
void    command_exec(t_cmd *cmd, t_env *env);
void    pipes_exec(t_cmd *cmd, t_env *env);
void    setup_pipes(t_cmd *cmd);

//redirect
void    remove_redirection(t_cmd *cmd, int i);
void    redirect_in(t_cmd *cmd, int i);
void    redirections(t_cmd *cmd);
void    redirect_here(t_cmd *cmd);

//Builtins
void	builtin_cd(t_env *env, t_cmd *cmd);
void	builtin_unset(t_env *env, t_cmd *cmd);
void	builtin_export(t_env *env, t_cmd *cmd);
void	builtin_exit(t_cmd *ms, char **cmd);
void	builtin_env(t_env *env);
void	builtin_pwd(t_cmd *cmd);
void	builtin_echo(char **cmd);

//Utils
int	ft_strcmp(char *s1, char *s2);
int find_eq(char *str);
void	export_error(t_cmd *cmd, int i, char **str);
int	error_handler(char *cmd);

#endif