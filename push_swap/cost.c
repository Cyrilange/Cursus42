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



int calculate_cost(t_stack_node **stack, t_stack_node *node)
{
    int cost;
	int stack_size;

	stack_size = stack_len(*stack);
    if (!stack || !*stack || !node)
    		return (-1);
	if (node->positioned <= stack_size / 2)
        cost = node->positioned;
    else
        cost = node->positioned - stack_size;

    return cost;
}

