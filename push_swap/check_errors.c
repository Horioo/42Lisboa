/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:42:01 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/01/30 16:30:40 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int 	error_sintax(char *s)
{
	int	i;

	i = -1;
	
	if(s[0] != '+' && s[0] != '-' && (s[0] < '0' || s[0] > '9'))
		return (1);
	if((s[0] == '-' || s[0] == '+') && (s[1] < '0' || s[1] > '9'))
		return (1);
	while(s[++i])
	{
		if(s[i] < '0' || s[i] > '9')
			return (1);
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node *tmp;
	t_stack_node *current;

	if(!stack)
		return ;
	current = *stack;
	while(current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int		check_dups(t_stack_node *a, int n)
{
	if(!a)
		return (0);
	while(a)
	{
		if(a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}


