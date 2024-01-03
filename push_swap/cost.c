/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:45:16 by marvin            #+#    #+#             */
/*   Updated: 2024/01/03 10:45:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calcula o custo para mover cada elemento da stack B para a posição correta na stack A
// cost_b : representa o custo para ter o elemento no top da Stack B
// cost_a : representa o custo para ter o elemento na posição correta na Stack A

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;
	int 	size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while(tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if(tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos)* -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if(tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

// Encontra o elemento na Stack B com o menor custo para mover para a posição correta no A e move-o

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while(tmp)
	{
		if(nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_b) + nb_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}