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

int	get_position(t_stack_node *stack)
{
	int	position_middle;
	int i;

	i = 0;
	if (!stack)
		return (-1);
	position_middle = stack_len(stack) / 2;
	while (stack)
	{
		stack->positioned = i;
		if (i <= position_middle)
			stack->top_middle_stack = true;
		else
			stack->top_middle_stack = false;
		stack = stack->next;
		i++;
	}
	if (!stack)
		return (-1);
	return (position_middle);
}


t_stack_node	*find_max_node(t_stack_node *stack)
{
	int				highest;
	t_stack_node	*highest_node;

	if (!stack)
		return (NULL);
	highest = INT_MIN;
	highest_node = NULL;
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

	if (!stack)
		return (NULL);
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

void	get_target(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*aux;
	t_stack_node	*target;
	long 			choice_index;

	while (stack_b)
	{
		choice_index = LONG_MAX;
		aux = stack_a;
		while (aux)
		{
			if (aux->value > stack_b->value && aux->value < choice_index)
			{
				choice_index = aux->value;
				target = aux;
			}
			aux = aux->next;
		}
		if (choice_index == LONG_MAX)
			stack_b->target = find_min_node(stack_a);
		else
		stack_b->target = target;
		stack_b = stack_b->next;
	}
}