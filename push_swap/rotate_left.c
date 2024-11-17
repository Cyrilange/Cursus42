/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:29:28 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:29:28 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_node **stack_a, bool print)
{
	t_stack_node	*last;
	t_stack_node	*before_last;

	if(!*stack_a || !(*stack_a)->next)
		return ;
	last =  *stack_a;
	while(last->next)
	{
        before_last = last;
        last = last->next;
    }
	before_last->next = NULL;
	last->prev = NULL;
	last->next = *stack_a;
    (*stack_a)->prev = last;
    *stack_a = last;
	if (print == 1)
		write(1, "rra\n", 1);
}

void	rrb(t_stack_node **stack_b, bool print)
{
	t_stack_node	*last;
	t_stack_node	*before_last;

	if(!*stack_b || !(*stack_b)->next)
		return ;
	last =  *stack_b;
	while(last->next)
	{
        before_last = last;
        last = last->next;
    }
	before_last->next = NULL;
	last->prev = NULL;
	last->next = *stack_b;
    (*stack_b)->prev = last;
    *stack_b = last;
	if (print == 1)
		write(1, "rrb\n", 1);
}


void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print == 1)
		write(1, "rrr\n", 1);
}

