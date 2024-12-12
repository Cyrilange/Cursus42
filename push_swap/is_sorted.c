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

bool	is_sorted(t_stack_node *head)
{
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (false);
		head = head->next;
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
