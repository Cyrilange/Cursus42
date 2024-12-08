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

void sort_small(t_stack_node **stack)
{
   t_stack_node	*max_node;

	max_node = find_max_node(*stack);
	if (*stack == max_node)
		ra(stack, 1);
	else if ((*stack)->next == max_node)
		rra(stack, 1);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, 1);
}

void sort_four(t_stack_node **stack_a, t_stack_node **stack_b)
{
    int stack_size = stack_len(stack_a);
    t_stack_node *max_node;

  
    while (stack_size == 4)
    {
        max_node = find_max_node(*stack_a);
        if (*stack_a == max_node)  // Si le plus grand est en tête
            pb(stack_a, stack_b, false);  // On le pousse dans stack_b
        else
            ra(stack_a, false);  // Sinon on le déplace vers le bas
        stack_size--;
    }

    // Trier les 3 éléments restants dans stack_a
    sort_small(stack_a);

    // Réintégrer les éléments de stack_b dans stack_a
    while (*stack_b)
        pa(stack_a, stack_b, false);
}


void sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
    int stack_size = stack_len(stack_a);
    t_stack_node *max_node;

    while (stack_size == 5)
    {
        max_node = find_max_node(*stack_a);
        if (*stack_a == max_node)  // Si le plus grand est en tête
            pb(stack_a, stack_b, 1);  // On le pousse dans stack_b
        else
            ra(stack_a, 1);  // Sinon on le déplace vers le bas
        stack_size--;
    }

    // Trier les 3 éléments restants dans stack_a
    sort_small(stack_a);

    // Réintégrer les éléments de stack_b dans stack_a
    while (*stack_b)
        pa(stack_a, stack_b, 1);
}
