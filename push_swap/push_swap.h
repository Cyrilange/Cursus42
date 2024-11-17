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

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s_stack_node {
	int					value;
	int					index;
	bool				print;
	struct s_stack_node *next;
	struct s_stack_node *prev;
} t_stack_node;

t_stack_node	*create_node(int value);
void			push_to_stack(t_stack_node **head, int value);
bool			ft_is_digit(int	n);
bool			is_valid_integer(char	*str);
bool			is_duplicate(t_stack_node *head);
void			ft_putstr(const char *str);
int				ft_atol(const char *str);
bool			is_sorted(t_stack_node *head);
void			sa(t_stack_node **stack_a, bool print);
void			sb(t_stack_node **stack_b, bool print);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			ra(t_stack_node **stack_a, bool print);
void			rb(t_stack_node **stack_b, bool print);
void			rra(t_stack_node **stack_a, bool print);
void			rrb(t_stack_node **stack_b, bool print);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			pa(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void 			sort_small(t_stack_node **stack_a);
int				find_min_position(t_stack_node *stack);
int				stack_len(t_stack_node **stack);
void			move_to_top(t_stack_node **stack, int position);
void			move_index_to_stack_b(t_stack_node **stack_a, t_stack_node **stack_b);
//void			move(t_stack_node **stack_a, t_stack_node **stack_b, int cost_a, int cost_b);




#endif 