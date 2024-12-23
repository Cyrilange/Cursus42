/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-24 19:27:21 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-24 19:27:21 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack_node **stack_a, t_stack_node **stack_b,int  stack_size)
{
    stack_size = stack_len(*stack_a);
    while (!(is_sorted(*stack_a)))
    {
        if (stack_size == 2)
	        sa(stack_a, 1);
	    else if (stack_size == 3)
		    sort_small(stack_a);
	    else
		    sort_large(stack_a, stack_b);
    }	
}

void sort_large(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node *aux;
    int             len;
    aux = *stack_a;
    len = stack_len(aux);
    while (aux->index > 0)
    {
        if (len > 3)
            pb(stack_a, stack_b, 1);
        sort_small(stack_a);
        aux->index--;
    }
    
}

void	pivot(t_stack_node **stack, t_stack_node *hightest_node, char str)
{
	while (*stack != hightest_node)
	{
		if (str == 'a')
		{
			if (hightest_node->top_middle_stack)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (str == 'b')
		{
			if (hightest_node->top_middle_stack)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}