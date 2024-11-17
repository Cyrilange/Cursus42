/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:29:12 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:29:12 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *create_node(int value)
{
    t_stack_node *new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
    if (!new_node)
        return NULL;
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void push_to_stack(t_stack_node **head, int value)
{
    t_stack_node *new_node = create_node(value);
    if (!new_node)
        return;
    new_node->next = *head;
    if (*head != NULL)
        (*head)->prev = new_node;
    *head = new_node;
}

int	stack_len(t_stack_node **stack)
{
	int	len;
	t_stack_node *current;

	len = 0;
	current = *stack;
	while (current != NULL)
	{
		len++;
		current = current;
	}
	return (len);
}