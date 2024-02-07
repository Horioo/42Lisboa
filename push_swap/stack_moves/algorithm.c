/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:42:18 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/02/05 16:40:21 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *cheapest_node;

	cheapest_node = get_cheapest(*a);
	if(cheapest_node->above_med && cheapest_node->target_node->above_med)
		rotate_both(a, b, cheapest_node);
	else if(!(cheapest_node->above_med) && !(cheapest_node->target_node->above_med))
		rev_rotate_both(a, b, cheapest_node);
	prep_to_push(a, cheapest_node, 'a');
	prep_to_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_to_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	min_on_top(t_stack_node **a)
{
	while((*a)->nbr != find_min(*a)->nbr)
	{
		if(find_min(*a)->above_med)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int len_a;

	len_a = stack_len(*a);
	if(len_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	if(len_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	while(len_a-- > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while(*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
