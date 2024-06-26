/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:24:26 by luiberna          #+#    #+#             */
/*   Updated: 2024/06/26 15:55:33 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_list(char **list)
{
    int i;
    
    i = 0;
    while (list[i])
    {
        free(list[i]);
        i++;
    }
    free(list);
}
void    free_cmd(t_cmd *cmd)
{
    t_cmd *curr;
    
	if(!cmd)
		return ;
    curr = cmd;
    while (curr != NULL)
    {
        curr = cmd;
        cmd = cmd->next;
        free_list(curr->cmd);
        free(curr->path);
        if (curr->fd[0] != -1)
            close(curr->fd[0]);
        if (curr->fd[1] != -1)
            close(curr->fd[1]);
        free(curr);
    }
}
