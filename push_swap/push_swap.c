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

void	push_swap(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	stack_size;

	stack_size = stack_len(*stack_a);
	if (stack_size == 2)
		sa(stack_a, 1);
	else if (stack_size == 3)
		sort_small(stack_a);
	else if (stack_size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_size == 5)
		sort_five(stack_a, stack_b);
	else
		sort_large(stack_a, stack_b);
}

void    helper_push_swap(t_stack_node *stack_a, t_stack_node *stack_b)
{
    get_position(stack_a);
    get_position(stack_b);
    get_target(stack_a, stack_b);
    get_price(stack_a, stack_b);
    get_best_price(stack_b);
}
void sort_large(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node    *bottom;
    int             len;

    len = stack_len(*stack_a);
    pb(stack_b, stack_a, 1);
    if ( len == 3)
        sort_small(stack_a);
    while (*stack_b)
    {
        helper_push_swap(*stack_a, *stack_b);
        move_to_top(stack_a, stack_b);
    }
    get_position(*stack_a);
    bottom = find_min_node(*stack_a);
    if (bottom->top_middle_stack)
    {
        while (*stack_a != bottom)
            ra(stack_a, 1);     
    }
    else
        while (*stack_a != bottom)
            rra(stack_a, 1);
}