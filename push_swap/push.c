/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:29:23 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:29:23 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
    t_stack_node *aux;

    if (*stack_b == NULL)
        return ;
    aux = (*stack_b)->next;
    (*stack_b)->next = *stack_a;
    if (*stack_a)
        (*stack_a)->prev = *stack_b;

    *stack_a = *stack_b;
    *stack_b = aux;

    if (*stack_b) 
        (*stack_b)->prev = NULL;

    if (print == 1)
        ft_putstr("pa\n");
}

void pb(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
    t_stack_node *aux;

    if (*stack_a == NULL)
        return ;

    aux = (*stack_a)->next;
    (*stack_a)->next = *stack_b;
    if (*stack_b)
        (*stack_b)->prev = *stack_a;
    *stack_b = *stack_a;
    *stack_a = aux;

    if (*stack_a)
        (*stack_a)->prev = NULL;
    if (print == 1)
        ft_putstr("pb\n");
}
