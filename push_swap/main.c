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
	

	if (argc <= 2)
		return (1);
	a = NULL;
	b = NULL;
	stack_checked(&a, argv);
	if (!is_sorted(&a))
	{
		if (stack_len(&a) == 2)
		{
			sa(&a, 1);
			free_stack(&a);
		}
		else
		{
			push_swap(&a, &b);
			free_both(&a, &b);
		}
			
	}
	else
		write(1, "OK\n", 3);
	free_both(&a, &b);
}

