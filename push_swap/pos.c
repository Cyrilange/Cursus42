/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-23 10:50:19 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-23 10:50:19 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_stack_node *stack, t_stack_node *target)
{
	int	position;

	position = 0;
	while (stack && stack != target)
	{
		stack = stack->next;
		position++;
	}
	return (position);
}

t_stack_node	*find_max_node(t_stack_node *stack)
{
	int				highest;
	t_stack_node	*highest_node;

	if (!stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

t_stack_node	*find_min_node(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*min_node;

	current = stack;
	min_node = stack;
	while (current)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
