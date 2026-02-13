/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-24 19:27:21 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-24 19:27:21 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack_node **a, t_stack_node **b,
	t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	pos_index(*a);
	pos_index(*b);
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
	t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	pos_index(*a);
	pos_index(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	init_push(a, cheapest_node, 'a');
	init_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->number != find_min_node(*a)->number)
	{
		if (find_min_node(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		prep_for_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_small(a);
	while (*b)
	{
		prep_for_b(*a, *b);
		move_b_to_a(a, b);
	}
	pos_index(*a);
	min_on_top(a);
}
