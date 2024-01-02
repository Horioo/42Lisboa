/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:42:59 by marvin            #+#    #+#             */
/*   Updated: 2024/01/02 11:42:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Obtemos o node da Tail e da Head da stack e fazemos com que a Tail fique a apontar para a cabeça e a cabeça fique a apontar para nulo, fazendo assim com que a cabeça seja agora o ultimo node da lista

static void	rotate(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_tail(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

// do_ra , do_rb sao chamadas para fazer rotate as respetivas listas, e o do_rr é chamado para fazer rotate as duas listas em simultaneo

void do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

void do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}