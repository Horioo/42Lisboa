/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:04:17 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/02/06 16:03:39 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Incluir printf e libft

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>	
# include <unistd.h>

//Struct
typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_med;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node 	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

// Errors Handling
int 	error_sintax(char *s);
int		check_dups(t_stack_node *a, int n);
void	free_stack(t_stack_node **stack);
void	free_errors(t_stack_node **a);
void	free_av(char **av);

//Random ass shit
void	print_list(t_stack_node *a);

// Stack Initialization
char	**ft_split(char *s, char c);
void	init_stack_a(t_stack_node **a, char **av);

// Nodes Initialization
void			current_index(t_stack_node *a);
void			set_target_a(t_stack_node *a, t_stack_node *b);
void			cost_analysis_a(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *a);
t_stack_node 	*get_cheapest(t_stack_node *a);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			set_target_b(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);

// Stack Utils
t_stack_node	*find_min(t_stack_node *a);
t_stack_node	*find_max(t_stack_node *a);
t_stack_node	*find_last(t_stack_node *a);
bool			is_sorted(t_stack_node *a);
int				stack_len(t_stack_node *a);
t_stack_node 	*lst_remove_tail(t_stack_node **stack);
t_stack_node 	*lst_remove_head(t_stack_node **stack);
void lst_add_tail(t_stack_node **stack, t_stack_node *node);
void lst_add_head(t_stack_node **stack, t_stack_node *node);

// Commands
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **b, t_stack_node **a);
void	rra(t_stack_node **a);
void	rrb(t_stack_node **a);
void	rrr(t_stack_node **a, t_stack_node **b);
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);
void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
void 	rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
void	prep_to_push(t_stack_node **stack, t_stack_node *top_node, char s_name);


// Algorithm
void	sort_three(t_stack_node **a);
void	sort_stacks(t_stack_node **a, t_stack_node **b);

#endif