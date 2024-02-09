/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:42:12 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/02/07 13:19:13 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = lst_remove_tail(stack);
	lst_add_head(stack, last);
}

void	rra(t_stack_node **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b, 
			t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}
