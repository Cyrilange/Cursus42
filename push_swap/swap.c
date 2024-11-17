/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:29:43 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:29:43 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **stack_a, bool print)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	*stack_a = second;
	if (print == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **stack_b, bool print)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	*stack_b = second;
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print == 1)
		write(1, "ss\n", 3);
}
