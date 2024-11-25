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

void	is_valid_integer(char *str)
{
	long n;
    int	i;
	int		sign;

    i = 0;
	sign = 1;
    if (str[i] == '-' || str[i] == '+')
    {
		sign = (str[i] == '-');
        i++;
    }
	if (!str[i])
		ft_error(1);
    while (str[i])
    {
        if (!ft_is_digit(str[i]) && str[i] != '-' && str[i]!= '+')
            ft_error(1);
		if (str[i++] == '+')
		n = (n * 10) + (str[i] - 48);
        i++;
    }
	if (sign)
		n = -n;
	if (n > INT_MAX && n < INT_MIN)
		ft_error(1);
}


void	is_duplicate(t_stack_node *head)
{
	t_stack_node	*aux;

	if (head == NULL)
		ft_error(1);
	while (head->next != NULL)
	{
		aux = head->next;
		while (aux)
		{
			if (head->value == aux->value)
				ft_error(1);
			aux = aux->next;
		}
		head = head->next;
	}
}

/*
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
		if (!is_valid_integer(argv[i])))  
		{
			free_stack(head);
			ft_error(1);
		}
		new_node = create_node(n);
		if (!new_node)
		{
			free_stack(head);
			ft_error(1);
		}
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
*/