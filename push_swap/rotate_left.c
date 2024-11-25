/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:29:28 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:29:28 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_node **stack_a, bool print)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	// Vérifiez si la liste est vide ou n'a qu'un seul élément
	if (!*stack_a || !(*stack_a)->next)
		return ;

	// Parcourir la liste pour trouver le dernier et l'avant-dernier élément
	last = *stack_a;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}

	// Déconnecter le dernier élément de l'avant-dernier
	second_last->next = NULL;

	// Réattacher le dernier élément au début
	last->next = *stack_a;
	last->prev = NULL; // Nouveau début de la liste
	(*stack_a)->prev = last;
	*stack_a = last;

	// Imprimer si nécessaire
	if (print == true)
		write(1, "rra\n", 4);
}


void	rrb(t_stack_node **stack_b, bool print)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	// Vérifiez si la liste est vide ou n'a qu'un seul élément
	if (!*stack_b || !(*stack_b)->next)
		return ;

	// Parcourir la liste pour trouver le dernier et l'avant-dernier élément
	last = *stack_b;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}

	// Déconnecter le dernier élément de l'avant-dernier
	second_last->next = NULL;

	// Réattacher le dernier élément au début
	last->next = *stack_b;
	last->prev = NULL; // Nouveau début de la liste
	(*stack_b)->prev = last;
	*stack_b = last;

	// Imprimer si nécessaire
	if (print == true)
		write(1, "rra\n", 4);
}


void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print == 1)
		write(1, "rrr\n", 5);
}

