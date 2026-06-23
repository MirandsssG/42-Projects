/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:13:50 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/05/28 14:18:41 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "includes/libft/libft.h"
# include "includes/libftprintf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// Errors
int						error_syntax(char *str_n);

int						error_duplicate(t_stack_node *a, int n);

void					free_stack(t_stack_node **stack);

void					free_errors(t_stack_node **a);

// Helpers
t_stack_node			*find_last(t_stack_node *stack);

t_stack_node			*find_min(t_stack_node *stack);

t_stack_node			*find_max(t_stack_node *stack);

int						stack_len(t_stack_node *stack);

bool					stack_sorted(t_stack_node *stack);

char					**split(char *s, char c);

void					free_split(int ac, char **args);

// Initialize Nodes A
void					current_index(t_stack_node *stack);

void					set_cheapest(t_stack_node *stack);

void					initialize_nodes_a(t_stack_node *a, t_stack_node *b);

// Initialize Nodes B

void					initialize_nodes_b(t_stack_node *a, t_stack_node *b);

// Initialize Stack A

void					initialize_stack_a(t_stack_node **a, char **av, int ac);

t_stack_node			*get_cheapest(t_stack_node *stack);

// Sort Stacks
void					sort_stacks(t_stack_node **a, t_stack_node **b);

// Sort Three
void					sort_three(t_stack_node **a);

// Stack Sorted
bool					stack_sorted(t_stack_node *stack);

// Push

void					pa(t_stack_node **a, t_stack_node **b, bool print);

void					pb(t_stack_node **b, t_stack_node **a, bool print);

void					prep_for_push(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);

// Reverse Rotate

void					rra(t_stack_node **a, bool print);

void					rrb(t_stack_node **b, bool print);

void					rrr(t_stack_node **a, t_stack_node **b, bool print);

void					rev_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);

// Rotate

void					ra(t_stack_node **a, bool print);

void					rb(t_stack_node **a, bool print);

void					rr(t_stack_node **a, t_stack_node **b, bool print);

void					rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);

// Swap

void					sa(t_stack_node **a, bool print);

void					sb(t_stack_node **b, bool print);

void					ss(t_stack_node **a, t_stack_node **b, bool print);

#endif