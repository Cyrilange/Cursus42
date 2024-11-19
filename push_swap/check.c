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

void	stack_checked(t_stack_node **head, char **argv)
{
	long	n;
	int		i;
	t_stack_node *new_node;
	t_stack_node *current;

	i = 0;
	while (argv[i])
	{
		if (!is_valid_integer(argv[i]))
			ft_error(1);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_error(1);

		new_node = create_node(n);
		if (!*head) // Si la pile est vide, on initialise
			*head = new_node;
		else
		{
			current = *head;
			while (current->next) // Va au dernier nœud
				current = current->next;
			current->next = new_node; // Ajoute le nouveau nœud à la fin
			new_node->prev = current; // Met à jour le pointeur `prev`
		}

		if (is_duplicate(head)) // Vérifie les doublons après ajout
			ft_error(1);

		i++;
	}
}


