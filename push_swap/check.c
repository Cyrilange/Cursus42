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

static int	is_valid_integer(char *str)
{
	if (!(*str == '+' || *str == '-'
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

static int	is_duplicate(t_stack_node *head, int n)
{
	if (!head)
		return (0);
	while (head)
	{
		if (head->value == n)
			return (1);
		head = head->next;
	}
	return (0);
}

void	stack_checked(t_stack_node **stack_a, char **str)
{
	long	n;
	int		i;

	i = 0;
	while (str[i])
	{
		if (is_valid_integer(str[i]))
			ft_error(stack_a);
		n = ft_atol(str[i]);
		if (n > INT_MAX && n < INT_MIN)
			ft_error(stack_a);
		if (is_duplicate(*stack_a, (int)n))
			ft_error(stack_a);
		append_node(stack_a, (int)n);
		i++;
	}
}
