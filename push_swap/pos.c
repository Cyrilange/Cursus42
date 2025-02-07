/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-23 10:50:19 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-23 10:50:19 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_max_node(t_stack_node *stack)
{
	long				highest;
	t_stack_node		*highest_node;

	if (!stack)
		return (NULL);
	highest = LONG_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

t_stack_node	*find_min_node(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
int find_min_position(t_stack_node *stack)
{
    t_stack_node *min_node;
    int          position;

    // Appel à la fonction pour récupérer le nœud avec la valeur minimale
    min_node = find_min_node(stack);

    // Si la pile est vide, retourne une valeur d'erreur (par exemple -1)
    if (!min_node)
        return (-1);

    // Parcours de la pile pour trouver la position de min_node
    position = 0;
    while (stack)
    {
        if (stack == min_node)  // Si le nœud actuel est min_node, retourne la position
            return (position);
        stack = stack->next;
        position++;
    }

    return (-1);  // Au cas où quelque chose ne va pas
}


t_stack_node	*find_last_node(t_stack_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
