/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-11 15:06:15 by csalamit          #+#    #+#             */
/*   Updated: 2025-01-11 15:06:15 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void     set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
    t_stack_node	*target_node;
    long			best_match;
        while (b)
        {
			best_match = LONG_MAX;
			current_a = a;
			while (current_a)
			{
				if (current_a->number > b->number 
					&& current_a->number < best_match)
						{
							best_match = current_a->number;
							target_node = current_a;	
						}
			current_a = current_a->next;
			}
			if (best_match == LONG_MAX)
				b->target_node = find_min_node(a);
			else
				b->target_node = target_node;
			b = b->next;
		}
}

void   	prep_for_b(t_stack_node *a, t_stack_node *b)
{
	pos_index(a);
	pos_index(b);
	set_target_b(a, b);
}