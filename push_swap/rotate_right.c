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
	t_stack_node	*second;

	if(!*stack_a || !(*stack_a)->next)
		return ;
	first =  *stack_a;
	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	second = *stack_a;
	while(second->next)
		second = second->next;
	second->next = first;
	first->prev = second;
	first->next = NULL;
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **stack_b, bool print)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if(!*stack_b || !(*stack_b)->next)
		return ;
	first =  *stack_b;
	*stack_b = first->next;
	(*stack_b)->prev = NULL;
	second = *stack_b;
	while(second->next)
		second = second->next;
	second->next = first;
	first->prev = second;
	first->next = NULL;
	if (print == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print)
		write(1,"rr\n", 3);
}
