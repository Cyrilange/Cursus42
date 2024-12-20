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
	t_stack_node *current = stack;

	if (!current)
	{
		printf("The stack is empty.\n");
		return ;
	}
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}


int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	long				size;
	
	a = NULL;
	b = NULL;
	size = stack_len(a);
	if (argc < 2)
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_checked(&a, argv + 1);
	print_stack(a); 
	push_swap(&a, &b, size);
	printf("stack a: ");
	print_stack(a);
	free_stack(&a);
	free_stack(&b);
}

