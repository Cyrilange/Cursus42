/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:29:36 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:29:36 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack_node **stack_a)
{
	if (find_min_node(*stack_a) == (*stack_a))
	{
		rra(stack_a, 1);
		sa(stack_a, 1);
	}
	else if (find_max_node(*stack_a) == (*stack_a))
	{
		ra(stack_a, 1);
		if (!is_sorted(*stack_a))
			sa(stack_a, 1);
	}
	else
	{
		if (find_max_node(*stack_a) == (*stack_a)->next 
			&& find_min_node(*stack_a) == (*stack_a)->next->next)
			{
				rra(stack_a, 1);
			}
		else
			sa(stack_a, 1);
	}
	
}
/*First = 1 3 2 -> 2 1 3 -> 1 2 3
Second = 3 2 1 -> 2 1 3 -> 1 2 3
Third = 2 3 1 -> 1 2 3
      = 2 1 3 -> 1 2 3*/