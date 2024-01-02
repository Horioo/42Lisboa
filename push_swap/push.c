/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:44:55 by marvin            #+#    #+#             */
/*   Updated: 2024/01/02 10:44:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//função default do Push, que vai receber a list source e a list dest e que vai passar o primeiro elemento do Source para o Dest

static void	push(t_stack **src, t_stack **dest)
{
	t_stack *tmp;

	if(src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

// do_pa e do_pb sao chamadas para fazer push as respetivas listas

void do_pa(t_stack **stack_a, t_stack **stack_b )
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void do_pb(t_stack **stack_a, t_stack **stack_b )
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}