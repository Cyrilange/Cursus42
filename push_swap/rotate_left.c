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

void	rra(t_stack_node **stack_a, bool print)
{
	t_stack_node	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	last = find_last_node(*stack_a);
	last->prev->next = NULL;
	last->next = *stack_a;
	last->prev = NULL;
	*stack_a = last;
	last->next->prev = last;
	if (print == 1)
		write(1, "rra\n", 4);
}


void	rrb(t_stack_node **stack_b, bool print)
{
	rra(stack_b, 1);
	if (print == 1)
		write(1, "rrb\n", 4);
}


void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	rra(stack_a, 0);
	rra(stack_b, 0);
	if (print == 1)
		write(1, "rrr\n", 5);
}


