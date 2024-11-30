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

void	push_chunk_to_b(t_stack_node **stack_a, t_stack_node **stack_b, int min, int max)
{
	int	start_index;
	int	end_index;
	t_stack_node *node_to_move;
	start_index = 0;
	end_index = stack_len(stack_a);
	while ((node_to_move = find_in_range(*stack_a, min, max)) != NULL)
	{
		if (is_sorted_range(*stack_a, start_index, end_index))
			return ;
		move_to_top(stack_a, node_to_move);
		pb(stack_a, stack_b, 1);
	}
}


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

void	sort_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*max_node;

	while (*stack_b)
	{
		max_node = find_max_node(*stack_b);
		move_to_top(stack_b, max_node);
		pa(stack_a, stack_b, 1);
	}
}
