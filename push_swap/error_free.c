/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:28:44 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:28:44 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_error(bool err, t_stack_node **a, t_stack_node **b)
{
	if (err)
	{
		write(2, "Error\n", 6);
		free_stack(a);
		free_stack(b);
		exit(EXIT_FAILURE);
	}
}

void	free_stack(t_stack_node **a)
{
	t_stack_node	*current;

	while (*a)
	{
		current = (*a)->next;
		free(*a);
		*a = current;
	}
	*a = NULL;
}

void	free_both(t_stack_node **a, t_stack_node **b)
{
	free_stack(a);
	free_stack(b);
}

/* -----test_err--------
 #include <stdbool.h>
 #include <unistd.h>
 int main(int argc, char **argv)
 {
	if (argc == 2)
	{
		write(1, "OK\n", 3);
		return (1);
	}
	ft_error(1);
	return (0);
 }*/