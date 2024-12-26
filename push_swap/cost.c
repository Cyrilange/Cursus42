/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:29:54 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:29:54 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cheapest(t_stack_node *stack)
{
	long			cheap_value;
	t_stack_node	*cheap_node;

	if (!stack)
		return ;
	cheap_value = LONG_MAX;
	while (stack)
	{
		if (stack->push < cheap_value)
		{
			cheap_value = stack->push;
			cheap_node = stack;
		}
		stack = stack->next;
	}
	cheap_node->cheap = true;
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheap)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
