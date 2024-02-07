/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:12:24 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/02/06 16:13:16 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	print_list(t_stack_node *a)
{
	int i = 0;
	while(a)
	{
		printf("Node %d -> %d\n", i, (a)->nbr);
		//printf("Node %d -> Target_node->nbr = %d\n", i, (a)->target_node->nbr);
		i++;
		a = a->next;
	}
}

int main(int ac, char **av)
{
	t_stack_node *a;
	t_stack_node *b;

	a = NULL;
	b = NULL;
	if(ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if(ac == 2)
	{
		av = ft_split(av[1], ' ');
		init_stack_a(&a, av);
	}
	else
		init_stack_a(&a, av + 1);
	if(!is_sorted(a))
	{
		if(stack_len(a) == 2)
			sa(&a);
		else if(stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	free_av(av);
}
