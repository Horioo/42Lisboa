/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:41:39 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/02/07 12:50:33 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	stack_len(t_stack_node *a)
{
	int	len;

	if (!a)
		return (0);
	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

t_stack_node	*find_last(t_stack_node *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

t_stack_node	*find_min(t_stack_node *a)
{
	t_stack_node	*node;
	long			min;

	if (!a)
		return (NULL);
	min = LONG_MAX;
	while (a)
	{
		if (a->nbr < min)
		{
			min = a->nbr;
			node = a;
		}
		a = a->next; 
	}
	return (node);
}

t_stack_node	*find_max(t_stack_node *a)
{
	t_stack_node	*node;
	long			max;

	if (!a)
		return (NULL);
	max = LONG_MIN;
	while (a)
	{
		if (a->nbr > max)
		{
			max = a->nbr;
			node = a;
		}
		a = a->next; 
	}
	return (node);
}

bool	is_sorted(t_stack_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (false);
		a = a->next;
	}
	return (true);
}
