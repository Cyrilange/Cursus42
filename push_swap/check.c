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

bool	ft_is_digit(int n)
{
	if (n >= '0' && n <= '9')
		return (true);
	return (false);
}

bool	is_valid_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_duplicate(t_stack_node **head, int n)
{
	t_stack_node *aux;

	aux = *head;
	if (aux == NULL)
		return (0);
	while (aux)
	{
		if (aux->value == n)
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

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if ((!is_valid_integer(argv[i])) || (is_duplicate(head, (int)n)))
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
