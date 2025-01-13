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
	int					value;
	bool				top_middle_stack;
	bool				cheap;
	int					push;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}	t_stack_node;

int				ft_atol(const char *str);
int				stack_len(t_stack_node *stack);
int				get_hight_index(t_stack_node *stack);
bool			is_sorted(t_stack_node *head);
void			current_index(t_stack_node *stack);
void			ft_error(t_stack_node **a);
void			free_split(char **split);
void			ft_putstr(const char *str);
void			swap(t_stack_node **stack_a);
void			sa(t_stack_node **stack_a, bool print);
void			sb(t_stack_node **stack_b, bool print);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			ra(t_stack_node **stack_a, bool print);
void			rb(t_stack_node **stack_b, bool print);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			rr_both(t_stack_node **stack_a,
					t_stack_node **stack_b, t_stack_node *cheap_node);
void			rra(t_stack_node **stack_a, bool print);
void			rrb(t_stack_node **stack_b, bool print);
void			rrr(t_stack_node **stack_a,
					t_stack_node **stack_b, bool print);
void			rrr_both(t_stack_node **stack_a,
					t_stack_node **stack_b, t_stack_node *cheap_node);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			sort_small(t_stack_node **stack);
void			free_stack(t_stack_node **stack);
void			print_stack(t_stack_node *stack);
void			append_node(t_stack_node **stack, int nbr);
void			stack_checked(t_stack_node **stack_a, char **str);
void			free_both(t_stack_node **a, t_stack_node **b);
void			sort_large(t_stack_node **stack_a);
void			push_swap(t_stack_node **stack_a, t_stack_node **stack_b);
t_stack_node	*find_max_node(t_stack_node *stack);
t_stack_node	*find_min_node(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *head);
t_stack_node	*get_cheapest(t_stack_node *stack);
char			**ft_split(char const *s, char c);
char			*ft_strndup(const char *src, size_t n);
void			calculate_cheapest(t_stack_node *stack);
void			initiation(t_stack_node *stack_a, t_stack_node *stack_b);
void			initiation_b(t_stack_node *stack_a, t_stack_node *stack_b);
void			move_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b);
void			move_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b);
void			pivot(t_stack_node **stack,
					t_stack_node *hightest_node, char str);

#endif