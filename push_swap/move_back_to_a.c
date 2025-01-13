/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-11 15:06:15 by csalamit          #+#    #+#             */
/*   Updated: 2025-01-11 15:06:15 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	calculate_target_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*aux;
	t_stack_node	*target_node;
	long			match_for_closest_smallest_number;

	while (stack_b)
	{
		match_for_closest_smallest_number = LONG_MAX;
		aux = stack_a;
		while (aux)
		{
			if (aux->value > stack_b->value
				&& aux->value < match_for_closest_smallest_number)
			{
				match_for_closest_smallest_number = aux->value;
				target_node = aux;
			}
			aux = aux->next;
		}
		if (match_for_closest_smallest_number == LONG_MAX)
			stack_b->target = find_min_node(stack_a);
		else
			stack_b->target = target_node;
		stack_b = stack_b->next;
	}
}

void	initiation_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	calculate_target_b(stack_a, stack_b);
}

void	move_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	pivot(stack_a, (*stack_b)->target, 'a');
	pa(stack_a, stack_b);
}
