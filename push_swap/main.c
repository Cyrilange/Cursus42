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

void	print_stack(t_stack_node *stack)
{
	if (!stack)
	{
		printf("The stack is empty.\n");
		return ;
	}
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
    }
	printf("\n");
}


int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	a = NULL;
	b = NULL;
	stack_checked(&a, argv);
	print_stack(a); 
	if (!is_sorted(&a))
	{
		push_swap(&a, &b);
		print_stack(a);
	}
	else
		write(1, "OK\n", 3);
	print_stack(a);
	free_both(&a, &b);
	print_stack(a);
}

