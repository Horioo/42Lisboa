/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:42:01 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/02/15 14:52:49 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	error_sintax(char *s)
{
	int	i;

	if (s[0] != '+' && s[0] != '-' && (s[0] < '0' || s[0] > '9'))
		return (1);
	if ((s[0] == '-' || s[0] == '+') && (s[1] < '0' || s[1] > '9'))
		return (1);
	if (s[0] == '-' || s[0] == '+')
		i = 1;
	else
		i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	check_dups(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_errors(t_stack_node **a, char **av, int ac)
{
	free_stack(a);
	free_av(av, ac);
	ft_printf("Error\n");
	exit(1);
}
