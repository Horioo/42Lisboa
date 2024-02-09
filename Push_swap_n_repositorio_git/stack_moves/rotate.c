/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:42:09 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/02/07 13:01:29 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*head;

	if (!*stack || !(*stack)->next)
		return ;
	head = lst_remove_head(stack);
	lst_add_tail(stack, head);
}

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}
