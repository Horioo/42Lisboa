/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:03:07 by marvin            #+#    #+#             */
/*   Updated: 2024/01/03 11:03:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Roda as duas stacks ao mesmo tempo ate uma estar na posição correta
// O custo é negativo visto que ambos os nodes a serem movimentados estao na metade de baixo das respetivas stacks

static void		do_rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while(*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

// Roda as duas stacks ao mesmo tempo ate uma estar na posição correta
// O custo é positivo visto que ambos os nodes a serem movimentados estao na metade de cima das respetivas stacks

static void		do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while(*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

// Roda a Stack A ate estar na posição correta

static void	do_rotate_a(t_stack **a, int *cost)
{
	while(*cost)
	{
		if(*cost > 0)
		{
			do_ra(a);
			(*cost)--;
		}
		else if(*cost < 0)
		{
			do_rra(a);
			(*cost)++;
		}
	}
}

static void	do_rotate_b(t_stack **b, int *cost)
{
	while(*cost)
	{
		if(*cost > 0)
		{
			do_rb(b);
			(*cost)--;
		}
		else if(*cost < 0)
		{
			do_rrb(b);
			(*cost)++;
		}
	}
}

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if(cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if(cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	do_pa(a, b);
}

