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

void	get_price(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_b)
	{
		stack_b->cost = stack_b->positioned;
		if (!(stack_b->top_middle_stack))
			stack_b->cost = len_b - (stack_b->positioned);
		if (stack_b->target->top_middle_stack)
			stack_b->cost += stack_b->target->positioned;
		else
			stack_b->cost += len_a - (stack_b->target->positioned);
		stack_b = stack_b->next;
	}
}

void	get_best_price(t_stack_node *stack_b)
{
    long            best_price;
    t_stack_node    *best_price_node;

    if (stack_b == NULL)
        return ;
    best_price = LONG_MAX;
    while (stack_b)
    {
        if (stack_b->cost < best_price)
        {
            best_price = stack_b->cost;
            best_price_node = stack_b;
        }
        stack_b = stack_b->next;
    }
    best_price_node->priceless = true;
}

t_stack_node	*best_node_to_choose(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->priceless)
			return (stack);
	stack = stack->next;
	}
	return (NULL);
}