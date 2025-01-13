/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:29:23 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:29:23 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **stack_d, t_stack_node **stack_s)
{
	t_stack_node	*push_node;

	if (!*stack_s)
		return ;
	push_node = *stack_s;
	*stack_s = (*stack_s)->next;
	if (*stack_s)
		(*stack_s)->prev = NULL;
	push_node->prev = NULL;
	if (!*stack_d)
	{
		*stack_d = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *stack_d;
		push_node->next->prev = push_node;
		*stack_d = push_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
