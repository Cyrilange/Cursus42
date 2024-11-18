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

bool	ft_error(bool error)
{
	if (error == 1)
	{
		write(1, "Error\n", 7);
		return (true);
	}
	return (false);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*aux;

	if (*stack == NULL)
		return ;
	while (*stack != NULL)
	{
		aux = (*stack)->next;
		free(*stack);
		*stack = aux;
	}
	*stack = NULL;
	free(aux);
}

void	stack_checked(t_stack_node **stack, char **argv, int argc)
{
	long	n;
	int		i;

	while (argv[i])
	{
		if (!is_valid_integer(argv[i]))
			ft_error(1);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_error(1);
		if (is_duplicate(stack))
			ft_error(1);
		create_node(n);
		i++;
	}
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