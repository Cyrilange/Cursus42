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

void sort_small(t_stack_node **stack_a)
{
    if ((*stack_a)->value > (*stack_a)->next->value) 
    {
        if ((*stack_a)->next->value > (*stack_a)->next->next->value)
            sa(stack_a, 1);
        else if ((*stack_a)->value > (*stack_a)->next->next->value)
            ra(stack_a, 1);
        else
            sa(stack_a, 1);
    }
    if (!is_sorted(stack_a))
        rra(stack_a, 1);
}

void sort_four(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node *min_node;

     while (stack_len(*stack_a) > 3)
    {
        min_node = find_min_node(*stack_a);
        if (*stack_a == min_node)
            pb(stack_a, stack_b, 1);
        else
            ra(stack_a, 1);
    }
    sort_small(stack_a);
    while (*stack_b)
        pa(stack_a, stack_b, 1);
}


void sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node *min_node;
    while (stack_len(*stack_a) > 3)
    {
        min_node = find_min_node(*stack_a);
        if (*stack_a == min_node)
                pb(stack_a, stack_b, 1);
        else
            ra(stack_a, 1);
    }
    if (!is_sorted(stack_a))
        sort_small(stack_a);
    while (*stack_b)
        pa(stack_a, stack_b, 1);
    sort_small(stack_a);
}
