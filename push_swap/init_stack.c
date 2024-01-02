/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:45:19 by marvin            #+#    #+#             */
/*   Updated: 2024/01/02 15:45:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Preencher a stack_a com os valores inseridos, se os valores nao forem estiverem dentro do valor do int dá erro e fecha o programa

t_stack	*fill_stack_values(int ac, char **av)
{
	int			i;
	long int	nb;
	t_stack		*node;

	node = NULL;
	nb = 0;
	i = 1;
	while(i < ac)
	{
		nb = ft_atoi(av[i]);
		if(nb > INT_MAX || nb < INT_MIN)
			exit_error(&node, NULL);
		if(i == 1)
			node = stack_new((int)nb);
		else
			stack_add_bottom(&node, stack_new((int)nb));
		i++;
	}
	return (node);
}

// Atribuir index é uma forma mais facil de ordenar os numeros dentro da stack

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack *ptr;
	t_stack *highest;
	int		value;

	while(--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while(ptr)
		{
			if(ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if(ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if(highest != NULL)
			highest->index = stack_size;
	}
}


