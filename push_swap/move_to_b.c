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

void	current_index(t_stack_node *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (!stack)
		return ;
	middle = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= middle)
			stack->top_middle_stack = true;
		else
			stack->top_middle_stack = false;
		stack = stack->next;
		++i;
	}
}

void	calculate_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push = b->index;
		if (!(b->top_middle_stack))
			b->push = len_b - (b->index);
		if (b->target_node->top_middle_stack)
			b->push += b->target_node->index;
		else
			b->push += len_a - (b->target_node->index);
		b = b->next;
	}
}

void	initiation(t_stack_node *stack_a, t_stack_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	calculate_target(stack_a, stack_b);
	calculate_cost(stack_a, stack_b);
	calculate_cheapest(stack_b);
}

void	move_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheap_node;

	cheap_node = get_cheapest(*stack_a);
	if (cheap_node->top_middle_stack && cheap_node->target_node->top_middle_stack)
		rr_both(stack_a, stack_b, cheap_node);
	else if (!(cheap_node->top_middle_stack) && !(cheap_node->target_node->top_middle_stack))
		rrr_both(stack_a, stack_b, cheap_node);
	pivot(stack_b, cheap_node, 'b');
	pivot(stack_a, cheap_node->target_node, 'a');
	pb(stack_b, stack_a, 1);
}
