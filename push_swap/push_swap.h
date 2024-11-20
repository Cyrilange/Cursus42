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
#include <limits.h>


typedef struct s_stack_node {
	int					value;
	int					index;
	int					position;
	int					size;
	bool				print;
	struct s_stack_node *next;
	struct s_stack_node *prev;
} t_stack_node;


bool			ft_is_digit(int	n);
bool			is_valid_integer(char	*str);
bool			is_duplicate(t_stack_node **head, int n);
void			ft_error(bool error);
void			ft_putstr(const char *str);
long			ft_atol(const char *str);
bool			is_sorted(t_stack_node **head);
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
void			sort_small(t_stack_node **stack);
void			free_stack(t_stack_node **stack);
int				stack_len(t_stack_node **stack);
void			stack_checked(t_stack_node **head, char **argv);
void			free_both(t_stack_node **a, t_stack_node **b);
int				*create_sorted_array(t_stack_node *stack, int size);
void			quicksort(int *arr, int low, int high);
int				partition(int *arr, int low, int high);
void			sort_large(t_stack_node **stack_a, t_stack_node **stack_b, int size);
void			push_swap(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_five(t_stack_node **stack_a, t_stack_node **stack_b);
void 			move_to_top(t_stack_node **stack, t_stack_node *target);
int 			get_position(t_stack_node *stack, t_stack_node *target);
void			push_chunk_to_b(t_stack_node **stack_a, t_stack_node **stack_b, int min, int max);
void			sort_b(t_stack_node **stack_a, t_stack_node **stack_b);
t_stack_node	*find_max_node(t_stack_node *stack);
t_stack_node 	*find_min_node(t_stack_node *stack);
t_stack_node	*find_in_range(t_stack_node *stack, int min, int max);
t_stack_node	*create_node(int value);








#endif