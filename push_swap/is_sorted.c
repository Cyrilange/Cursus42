/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:28:52 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:28:52 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack_node **head)
{
	t_stack_node	*current;

	current = *head;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

bool	is_sorted_range(t_stack_node *stack, int start, int end)
{
	int	i;

	i = 0;

	if (!stack || start > end)
		return (false);
	while (++i < start && stack)
		stack = stack->next;
	while (i < end && stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
		i++;
	}
	return (true);
}
