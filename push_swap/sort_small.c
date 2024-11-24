/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:29:36 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:29:36 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack_node **stack)
{
	t_stack_node	*high;

	high = find_max_node(*stack);
	if (*stack == high)
		ra(stack, 1);
	else if ((*stack)->next == high)
		rra(stack, 1);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, 1);
}

void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*min_node;

	while (stack_len(stack_a) > 3)
	{
		min_node = find_min_node(*stack_a);
		move_to_top(stack_a, min_node);
		pb(stack_a, stack_b, 1);
	}
	sort_small(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}
