/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:42:03 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/01/30 16:21:47 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		swap(t_stack_node **head)
{
	if(!*head || !(*head)->next)
		return ;
	int tmp_nbr;
	int tmp_index;
	t_stack_node *next;

	next = (*head)->next;
	tmp_nbr = (*head)->nbr;
	tmp_index = (*head)->index;
	(*head)->nbr = (next)->nbr;
	(*head)->index = (next)->index;
	(next)->nbr = tmp_nbr;
	(next)->index = tmp_index;
}

void	sa(t_stack_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
