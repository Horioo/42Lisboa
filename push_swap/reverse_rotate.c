/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:34:21 by marvin            #+#    #+#             */
/*   Updated: 2024/01/02 11:34:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Pegamos o valor do ultimo node(tail) e o valor do penultimo node(before tail), depois metemos o ultimo node como primeiro, fazendo o apontar para a cabeça da lista, e metemos o before_tail a apontar para null

static void	rev_rotate(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tail;
	t_stack *b_tail;

	tail = get_tail(*stack);
	b_tail = get_b_tail(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	b_tail->next = NULL;
}

// do_rra , do_rrb sao chamadas para fazer reverse rotate as respetivas listas, e o do_rrr é chamado para fazer reverse rotate as duas listas em simultaneo

void do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

void do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

void do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);	
	ft_putstr("rrr\n");
}