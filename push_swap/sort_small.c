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
    t_stack_node *hight;

    hight = find_max_node(*stack_a);
        if (hight == *stack_a)
            ra(stack_a, 1);
        else if ((*stack_a)->next == hight)
            rra(stack_a, 1);
        if ((*stack_a)->value > (*stack_a)->next->value)
            sa(stack_a, 1);
    
}
