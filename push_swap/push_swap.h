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
	int					value;
	int					positioned;
	int					size;
	int					cost;
	bool				print;
	bool				top_middle_stack;
	bool				priceless;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node *target;
}	t_stack_node;

typedef struct sort_large_s
{
	int	chunk_size;
	int	num_chunks;
	int	i;
	int	min;	
	int	max;
}	t_sort_large;

long			ft_atol(const char *str);
int				is_valid_integer(char	*str);
int				is_duplicate(t_stack_node *head, int value);
void			get_price(t_stack_node *stack_a, t_stack_node *stack_b);
int				stack_len(t_stack_node *stack);
int				get_position(t_stack_node *stack);
int				num_words(const char *s, char c);
bool			is_sorted_range(t_stack_node *stack, int start, int end);
bool			is_sorted(t_stack_node **head);
void			ft_error(bool err, t_stack_node **a, t_stack_node **b);
void			error_free(t_stack_node **a, char **argv, bool flag_argc_2);
void			free_split(char **split) ;
void			ft_putstr(const char *str);
void			swap(t_stack_node **stack_a);
void			sa(t_stack_node **stack_a, bool print);
void			sb(t_stack_node **stack_b, bool print);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			ra(t_stack_node **stack_a, bool print);
void			rb(t_stack_node **stack_b, bool print);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			rot_rr(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *priceles);
void			rra(t_stack_node **stack_a, bool print);
void			rrb(t_stack_node **stack_b, bool print);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			rot_rrr(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *priceles);
void			pa(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			sort_small(t_stack_node **stack);
void			free_stack(t_stack_node **stack);
void			print_stack(t_stack_node *stack);
void			free_split(char **split);
void			append_node(t_stack_node **stack, int nbr);
void			sort_four(t_stack_node **stack_a, t_stack_node **stack_b);
void 			sort_five(t_stack_node **stack_a, t_stack_node **stack_b);
void			get_target(t_stack_node *stack_a, t_stack_node *stack_b);
void			get_best_price(t_stack_node *stack_b);
void			stack_checked(t_stack_node **head, char **argv, bool argc_2);
void			free_both(t_stack_node **a, t_stack_node **b);
void			sort_large(t_stack_node **stack_a,
					t_stack_node **stack_b);
void			push_swap(t_stack_node **stack_a, t_stack_node **stack_b);
void			move_to_top(t_stack_node **stack, t_stack_node **stack_b);
void			pivot(t_stack_node **stack, t_stack_node *hightest_node, char str);
t_stack_node	*find_max_node(t_stack_node *stack);
t_stack_node	*find_min_node(t_stack_node *stack);
t_stack_node	*find_in_range(t_stack_node *stack, int min, int max);
t_stack_node	*find_last_node(t_stack_node *head);
t_stack_node	*create_node(long value);
t_stack_node	*best_node_to_choose(t_stack_node *stack);
char			*ft_strndup(const char *src, size_t n);
char			*get_next_word(const char **s, char c);
char			**ft_split(char const *s, char c);

#endif