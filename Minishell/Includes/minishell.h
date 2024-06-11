/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:58:43 by luiberna          #+#    #+#             */
/*   Updated: 2024/06/05 16:20:56 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>
# include <termios.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>

	#ifndef PATH_MAX
		# define PATH_MAX 1024
	#endif

typedef struct s_amb
{
    char **envp;
    struct s_env *next;
    struct s_env *prev;
}               t_amb;

typedef struct s_cmd
{
    char **cmd;
    char *path;
    int fd[2];
    pid_t pid;
    int nb_cmds;
    struct s_cmd *next;
    struct s_cmd *prev;
}               t_cmd;

//init
char	*get_path(char *cmd, char **envp);
t_cmd   *create_cmd(char *sep_cmd, t_cmd *prev_cmd, int i, char **envp);
t_cmd   *init_cmd(char *input, char **envp);

//parse
t_cmd   *lexer_args(char *input, char **envp);

//free
void    free_list(char **list);
void    free_cmd(t_cmd *cmd);

#endif