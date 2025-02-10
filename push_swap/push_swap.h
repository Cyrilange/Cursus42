/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:29:17 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:29:17 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					index;
	int					number;
	bool				above_median;
	bool				cheapest;
	int					push_cost;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target_node;
}	t_stack_node;

int				stack_len(t_stack_node *stack);
int				is_not_duplicate(t_stack_node *a, int n);
int				is_not_number(char *str_n);
bool			is_sorted(t_stack_node *stack);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);
void			stacked_checked(t_stack_node **a, char **str);
char			**ft_split(char const *s, char c);
void			pos_index(t_stack_node *stack);
void			prep_for_b(t_stack_node *a, t_stack_node *b);
void			prep_for_a(t_stack_node *a, t_stack_node *b);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			init_push(t_stack_node **stack,
					t_stack_node *top_node, char stack_name);
t_stack_node	*find_last_node(t_stack_node *stack);
t_stack_node	*find_min_node(t_stack_node *stack);
t_stack_node	*find_max_node(t_stack_node *stack);
void			sort_small(t_stack_node **a);
void			push_swap(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **stack_a, bool print);
void			sb(t_stack_node **stack_b, bool print);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
void			rra(t_stack_node **stack_a, bool print);
void			rrb(t_stack_node **stack_b, bool print);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			ra(t_stack_node **stack_a, bool print);
void			rb(t_stack_node **stack_b, bool print);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);

#endif