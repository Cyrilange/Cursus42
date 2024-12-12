/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:28:39 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:28:39 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid_integer(char *str)
{
    if (!(*str == '+'
			|| *str == '-'
			|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+'
			|| *str == '-')
		&& !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}


int	is_duplicate(t_stack_node *head, int n)
{
	if (NULL == head)
		return (0);
	while (head)
	{
		if (head->value == n)
			return (1);
		head = head->next;
	}
	return (0);
}


void	index_checked(t_stack_node *stack_a, int size)
{
	t_stack_node	*stack;
	t_stack_node	*hight;
	int				value;

	while (--size > 0)
	{
		stack = stack_a;
		value = INT_MIN;
		hight = NULL;
		while (stack)
		{
			if (stack->value > value && stack->index == 0)
			{
				value = stack->value;
				hight = stack;
			}
			stack = stack->next;
		}
		if (hight)
			hight->index = size;
	}
}

t_stack_node *stack_value(int n, char **str)
{
    t_stack_node		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < n)
	{
		nb = ft_atoi(str[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error(&stack_a);
		if (i == 1)
			stack_a = create_node((int)nb);
		else
			last_node_plus(&stack_a, create_node((int)nb));
		i++;
	}
	return (stack_a);
}
