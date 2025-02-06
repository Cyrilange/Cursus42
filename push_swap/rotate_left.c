/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:29:28 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:29:28 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_node **stack_a, bool print)
{
	rrotate(stack_a);
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if (!print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **stack_b, bool print)
{
	rrotate(stack_b);
	if (!print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	rrotate(stack_a);
	rrotate(stack_b);
	if (!print)
		write(1, "rrr\n", 5);
}
