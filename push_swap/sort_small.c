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
    int first = (*stack_a)->value;
    int second = (*stack_a)->next->value;
    int third = (*stack_a)->next->next->value;

    if (first > second && second < third && first < third)
        sa(stack_a, 1);
    else if (first > second && second > third)
    {
        sa(stack_a, 1);
        rra(stack_a, 1);
    }
    else if (first > second && second < third && first > third)
        ra(stack_a, 1);
    else if (first < second && second > third && first < third)
    {
        sa(stack_a, 1);
        ra(stack_a, 1);
    }
    else if (first < second && second > third && first > third)
        rra(stack_a, 1);
}

