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
    int hight;

    hight = get_hight_index(*stack_a);
        if ((*stack_a)->index == hight)
            ra(stack_a, 1);
        if ((*stack_a)->next->index == hight)
            rra(stack_a, 1);
        if ((*stack_a)->index > (*stack_a)->next->index)
            sa(stack_a, 1);
    
}
