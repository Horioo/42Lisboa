/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:41:50 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/02/15 15:07:27 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

long	ft_atol(char *s)
{
	long	l;
	int		i;
	int		sign;

	i = 0;
	l = 0;
	sign = 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' 
		|| s[i] == '\r' || s[i] == '\f' || s[i] == '\v')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		l = l * 10 + (s[i++] - '0');
		if (l > INT_MAX_2)
			return (l * sign);
	}
	return (l * sign);
}

void	append_node(t_stack_node **a, int n)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (!a)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*a))
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last = find_last(*a);
		last->next = node;
		node->prev = last;
	}
}

void	init_stack_a(t_stack_node **a, char **av, int ac)
{
	long	n;
	int		i;

	i = 0;
	n = 0;
	if (!av)
		return ;
	while (av[i])
	{
		if (error_sintax(av[i]))
			free_errors(a, av, ac);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a, av, ac);
		if (check_dups(*a, (int)n))
			free_errors(a, av, ac);
		append_node(a, (int)n);
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *a)
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->cheapest)
			return (a);
		a = a->next;
	}
	return (NULL);
}

void	prep_to_push(t_stack_node **stack, t_stack_node *top_node, char s_name)
{
	while (*stack != top_node)
	{
		if (s_name == 'a')
		{
			if (top_node->above_med)
				ra(stack);
			else
				rra(stack);
		}
		else if (s_name == 'b')
		{
			if (top_node->above_med)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
