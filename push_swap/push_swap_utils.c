/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:29:12 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:29:12 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (NULL == stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->value = nbr;
	node->cheap = 0;
	if (NULL == *stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	stack_len(t_stack_node *stack)
{
	int				size;

	if (!stack)
		return (0);
	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	rr_both(t_stack_node **stack_a,
			t_stack_node **stack_b, t_stack_node *cheap_node)
{
	while (*stack_b != cheap_node->target && *stack_a != cheap_node)
		rr(stack_a, stack_b, false);
	current_index(*stack_a);
	current_index(*stack_b);
}

void	rrr_both(t_stack_node **stack_a,
			t_stack_node **stack_b, t_stack_node *cheap_node)
{
	while (*stack_b != cheap_node->target && *stack_a != cheap_node)
		rrr(stack_a, stack_b, false);
	current_index(*stack_a);
	current_index(*stack_b);
}
