/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 15:29:54 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-17 15:29:54 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*aux;
	int	i;

	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	aux = NULL;
	i = argc - 1;
	while (i > 0)
	{
		is_valid_integer(argv[i]);
		aux = create_node(ft_atol(argv[i]));
		aux->next = a;
		a = aux;
		i--;
	}
	is_duplicate(a);
	if (!is_sorted(&a))
	{
		if (stack_len(&a) == 2)
			sa(&a, 1);
		else
			push_swap(&a, &b);
	}
	else
		write(1, "OK\n", 3);
	free_both(&a, &b);
}

