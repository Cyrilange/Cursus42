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

void	sort_small(t_stack_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack, 1);
	else if (first > second && second > third)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (first > second && second < third && first > third)
		ra(stack, 1);
	else if (first < second && second > third && first < third)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (first < second && second > third && first > third)
		rra(stack, 1);
}

void sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
    while (stack_len(stack_a) > 3)
    {
        t_stack_node *min_node = find_min_node(*stack_a); // Trouve le nœud avec la plus petite valeur
        move_to_top(stack_a, min_node);                  // Amène le nœud au sommet de A
        pb(stack_a, stack_b, 1);                         // Pousse le plus petit élément dans B
    }
    sort_small(stack_a); // Trie les 3 éléments restants dans A
    while (*stack_b)
        pa(stack_a, stack_b, 1); // Ramène les éléments de B vers A
}

