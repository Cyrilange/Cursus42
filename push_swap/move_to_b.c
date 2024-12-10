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

void move_to_top(t_stack_node **stack, t_stack_node **stack_b)
{
	t_stack_node *cheap;

	cheap = best_node_to_choose(*stack_b);
	if (cheap->top_middle_stack && cheap->target->top_middle_stack)
		rot_rr(stack, stack_b, cheap);
	else if (!(cheap->top_middle_stack) && !(cheap->target->top_middle_stack))
		rot_rrr(stack, stack_b, cheap);
	pivot(stack_b, cheap, 'b');
	pivot(stack, cheap->target, 'a' );
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
