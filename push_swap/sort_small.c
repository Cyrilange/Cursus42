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
		rra(stack_a, false);
		sa(stack_a, false);
	}
	else if (find_max_node(*stack_a) == (*stack_a))
	{
		ra(stack_a, false);
		if (!is_sorted(*stack_a))
			sa(stack_a, false);
	}
	else
	{
		if (find_max_node(*stack_a) == (*stack_a)->next 
			&& find_min_node(*stack_a) == (*stack_a)->next->next)
			{
				rra(stack_a, false);
			}
		else
			sa(stack_a, false);
	}	
}

void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
	while (stack_len(*stack_a) > 3)
	{
		initiation(*stack_a, *stack_b);
		pivot(stack_a, find_min_node(*stack_a), 'a');
		pb(stack_b, stack_a, 1);
	}
}


/*First = 1 3 2 -> 2 1 3 -> 1 2 3
Second = 3 2 1 -> 2 1 3 -> 1 2 3
Third = 2 3 1 -> 1 2 3
      = 2 1 3 -> 1 2 3*/