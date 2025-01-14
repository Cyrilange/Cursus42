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
	middle = stack_len(stack) - get_lowest_index(stack);
	while (stack)
	{
		stack->index = i;
		if (i < middle)
			stack->top_middle_stack = true;
		else
			stack->top_middle_stack = false;
		stack = stack->next;
		i++;
	}
}

static	void	calculate_target(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*aux;
	t_stack_node	*target_node;
	long			match_for_closest_smallest_number;

	while (stack_a)
	{
		match_for_closest_smallest_number = LONG_MIN;
		aux = stack_b;
		while (aux)
		{
			if (aux->value < stack_a->value
				&& aux->value > match_for_closest_smallest_number)
			{
				match_for_closest_smallest_number = aux->value;
				target_node = aux;
			}
			aux = aux->next;
		}
		if (match_for_closest_smallest_number == LONG_MIN)
			stack_a->target = find_max_node(stack_b);
		else
			stack_a->target = target_node;
		stack_a = stack_a->next;
	}
}

static void	calculate_cost(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_a)
	{
		stack_a->push = stack_a->index;
		if (!(stack_a->top_middle_stack))
			stack_a->push = len_a - (stack_a->index);
		if (stack_a->target->top_middle_stack)
			stack_a->push += stack_a->target->index;
		else
			stack_a->push += len_b -(stack_a->target->index);
		stack_a = stack_a->next;
	}
}

void	initiation(t_stack_node *stack_a, t_stack_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	calculate_target(stack_a, stack_b);
	calculate_cost(stack_a, stack_b);
	calculate_cheapest(stack_a);
}

void	move_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheap_node;

	cheap_node = get_cheapest(*stack_a);
	if (cheap_node->top_middle_stack && cheap_node->target->top_middle_stack)
		rr_both(stack_a, stack_b, cheap_node);
	else if (!(cheap_node->top_middle_stack) && !(cheap_node->target->top_middle_stack))
		rrr_both(stack_a, stack_b, cheap_node);
	pivot(stack_a, cheap_node, 'a');
	pivot(stack_b, cheap_node->target, 'b');
	pb(stack_b, stack_a);
}
