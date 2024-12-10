/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-23 10:47:06 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-23 10:47:06 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_in_range(t_stack_node *stack, int min, int max)
{
	while (stack)
	{
		if (stack->value >= min && stack->value <= max)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	move_to_top(t_stack_node **stack, t_stack_node **stack_b)
{
	t_stack_node *smallest_node;

	smallest_node = best_node_to_choose(*stack_b);
	if (smallest_node->cost && smallest_node->target->top_middle_stack)
		rot_rr(stack, stack_b, smallest_node);
	else if (!(smallest_node->cost) && !(smallest_node->target->cost))
		rot_rrr(stack, stack_b, smallest_node);
	pivot(stack_b, smallest_node, 'b');
	pivot(stack, smallest_node, 'a');
	pa(stack, stack_b, 1);


}

void	pivot(t_stack_node **stack, t_stack_node *hightest_node, char str)
{
	while (*stack != hightest_node)
	{
		if (str == 'a')
		{
			if (hightest_node->top_middle_stack)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (str == 'b')
		{
			if (hightest_node->top_middle_stack)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}
