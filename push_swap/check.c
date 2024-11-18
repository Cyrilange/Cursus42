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
#include <unistd.h>

bool	ft_is_digit(int	n)
{
		if (n >= '0' && n <= '9')
			return (true);
		return (false);
}

bool	is_valid_integer(char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while(str[i])
	{
		if(!ft_is_digit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_duplicate(t_stack_node **head)
{
	t_stack_node *current = *head;
	while (current != NULL)
	{
		t_stack_node *check = current->next;
		while (check != NULL)
		{
			if (current->value == check->value)
				return (true);
			check = check->next;
		}
		current = current->next;
	}
	return (false);
}
