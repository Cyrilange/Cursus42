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

void sort_b(t_stack_node **stack_b, t_stack_node **stack_a)
{
    t_stack_node	*min_node;
	int				cost;
    
    while (*stack_b)
    {
		min_node = find_min_node(*stack_b);
        cost = calculate_cost(stack_b, min_node);
		if (cost > 0)
		{
			while (cost--)
				rb(stack_b, 1);
		}
		else
		{
			while (cost++)
				rrb(stack_b, 1);
		}
		pa(stack_b, stack_a, 1);
	}
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
