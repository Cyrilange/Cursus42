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
	t_stack_node	*aux;

	if(!*stack_a || !(*stack_a)->next)
		return ;
	last =  *stack_a;
	while(last->next)
		last = last->next;
	aux = last->next;
	last->prev = NULL;
	aux->next = *stack_a;
	*stack_a = aux;
	if (print == 1)
		write(1, "rra\n", 5);
}

void	rrb(t_stack_node **stack_b, bool print)
{
	t_stack_node	*last;
	t_stack_node	*aux;

	if(!*stack_b || !(*stack_b)->next)
		return ;
	last =  *stack_b;
	while(last->next)
		last = last->next;
	aux = last->next;
	last->prev = NULL;
	aux->next = *stack_b;
	*stack_b = aux;
	if (print == 1)
		write(1, "rra\n", 5);
}


void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print == 1)
		write(1, "rrr\n", 5);
}

