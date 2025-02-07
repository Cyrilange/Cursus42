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

void	push_swap(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	stack_size;
	
	stack_size = stack_len(*stack_a);
	if (stack_size-- > 3 && !(is_sorted(*stack_a)))
		pb(stack_b, stack_a, false);
	if (stack_size-- > 3 && !(is_sorted(*stack_a)))
		pb(stack_b, stack_a, false);
	while (stack_size-- > 3 && !(is_sorted(*stack_a)))
	{
		initiation(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_small(stack_a);
	while (*stack_b)
	{
		initiation_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	sort_large(stack_a);
}

void	sort_large(t_stack_node **stack_a)
{
	while ((*stack_a)->value != find_min_node(*stack_a)->value)
	{
		if (find_min_node(*stack_a)->top_middle_stack)
			ra(stack_a, false);
		else
			rra(stack_a, false);
	}
}

void	pivot(t_stack_node **stack, t_stack_node *hightest_node, char str)
{
	while (*stack != hightest_node)
	{
		if (str == 'a')
		{
			if (hightest_node->top_middle_stack)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (str == 'b')
		{
			if (hightest_node->top_middle_stack)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
