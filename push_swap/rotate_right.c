/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:28:24 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:28:24 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **stack_a, bool print)
{
	t_stack_node	*first;
	t_stack_node	*aux;

	if(!*stack_a || !(*stack_a)->next)
		return ;
	aux =  *stack_a;
	*stack_a = aux->next;
	first = *stack_a;
	while(first->next)
		first = first->next;
	first->next = aux;
	aux->next = NULL;
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **stack_b, bool print)
{
	t_stack_node	*first;
	t_stack_node	*aux;

	if(!*stack_b || !(*stack_b)->next)
		return ;
	aux =  *stack_b;
	*stack_b = aux->next;
	first = *stack_b;
	while(first->next)
		first = first->next;
	first->next = aux;
	aux->next = NULL;
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print)
		write(1,"rr\n", 3);
}
