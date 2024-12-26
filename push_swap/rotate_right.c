/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:28:24 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:28:24 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **stack_a, bool print)
{
	t_stack_node	*last_node;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return;
	last_node = find_last_node(*stack_a);
	last_node->next = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **stack_b, bool print)
{
	t_stack_node	*last_node;
	
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
        return;
	last_node = find_last_node(*stack_b);
	last_node->next = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	ra(stack_a, 0);
	ra(stack_b, 0);
	if (print)
		write(1,"rr\n", 3);
}
