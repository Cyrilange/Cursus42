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


void	stack_checked(t_stack_node **head, char **argv, bool argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (is_valid_integer(argv[i]))
			error_free(head, argv, argc_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(head, argv, argc_2);
		if (is_duplicate(*head, (int)nbr))
			error_free(head, argv, argc_2);
		append_node(head, (int)nbr);
		++i;
	}
	if (argc_2)
		free_split(argv);
}
