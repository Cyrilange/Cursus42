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

bool	ft_is_digit(char n)
{
	if (n >= '0' && n <= '9')
		return (true);
	return (false);
}

int	is_valid_integer(char *str)
{
	int		n;

	n = ft_atol(str);
	if (n > INT_MAX && n < INT_MIN)
		return (0);
    if (*str == '-' || (*str >= '0' && *str <= '9'))
	{
		while (*str)
		{
			if (*str < 0 && *str > 9)
				return (0);
			str++;
		}
		return (1);
	}
    return (0);
}


int	is_duplicate(t_stack_node *head, long value)
{
	t_stack_node	*aux;

	aux = head;
	while (aux != NULL)
	{
		if (aux->value == value)
			return (1);
		aux = aux->next;
	}
	return (0);
}


void	stack_checked(t_stack_node **head, char **argv)
{
	long			n;
	int				i;
	t_stack_node	*new_node;
	t_stack_node	*current;

	i = 1;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if ((!is_valid_integer(argv[i])))  
			ft_error(1);
		if (is_duplicate(*head, n))
			ft_error(1);
		new_node = create_node(n);
		if (!*head)
			*head = new_node;
		else
		{
			current = *head;
			while (current->next)
				current = current->next;
			current->next = new_node;
			new_node->prev = current;
		}
		i++;
	}
}
