/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:48:29 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/02/07 12:51:48 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_stack_node	*lst_remove_tail(t_stack_node **stack)
{
	t_stack_node	*tmp;

	tmp = find_last(*stack);
	tmp->prev->next = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

t_stack_node	*lst_remove_head(t_stack_node **stack)
{
	t_stack_node	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void	lst_add_tail(t_stack_node **stack, t_stack_node *node)
{
	t_stack_node	*tail;

	tail = find_last(*stack);
	tail->next = node;
	node->prev = tail;
}

void	lst_add_head(t_stack_node **stack, t_stack_node *node)
{
	t_stack_node	*head;

	head = *stack;
	if (!head)
		*stack = node;
	else
	{
		node->next = head;
		head->prev = node;
		*stack = node;
	}
}

void	free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
