/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:41:58 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/02/06 12:45:52 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	current_index(t_stack_node *a)
{
	int	i;
	int	median;

	i = 0;
	if(!a)
		return ;
	median = stack_len(a) / 2;
	while(a)
	{
		a->index = i;
		if(i <= median)
			a->above_med = true;
		else
			a->above_med = false;
		a = a->next;
		i++;
	}
}

void		set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while(a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while(current_b)
		{
			if(current_b->nbr < a->nbr && current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if(best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next; 
	}
}

void		cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int len_a;
	int len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while(a)
	{
		a->push_cost = a->index;
		if(!(a->above_med))
			a->push_cost = len_a - (a->index);
		if(a->target_node->above_med)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}

}

void	set_cheapest(t_stack_node *a)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if(!a)
		return ;
	cheapest_value	= LONG_MAX;
	while(a)
	{
		if(a->push_cost < cheapest_value)
		{
			cheapest_value = a->push_cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}