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
	t_stack_node *current = stack; // Use a temporary pointer to traverse the stack

	if (!current)
	{
		printf("The stack is empty.\n");
		return ;
	}
	while (current)
	{
		printf("%d ", current->value);
		current = current->next; // Move to the next node
	}
	printf("\n");
}


int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_checked(&a, argv + 1, argc == 2);
	print_stack(a); 
	if (!is_sorted(&a))
	{
		if (stack_len(a) == 2)
		{
			sa(&a, 1);
			print_stack(a);
		}
		else if (stack_len(a) == 3)
		{
			sort_small(&a);
			print_stack(a);
		}
			
		else
		{
			sort_large(&a, &b);
			printf("stack a: ");
			print_stack(a);
		}
	}
	else
		write(1, "OK\n", 3);
	free_stack(&a);
}

