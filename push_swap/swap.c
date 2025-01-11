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

void	swap(t_stack_node **stack_a)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	*stack_a = second;
}

void	sa(t_stack_node **stack_a, bool print)
{
	swap(stack_a);
	if (print == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **stack_b, bool print)
{
	swap(stack_b);
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
