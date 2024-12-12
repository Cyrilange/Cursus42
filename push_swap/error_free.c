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

void	ft_error(t_stack_node *a)
{
		free_stack(&a);
		exit(EXIT_FAILURE);
}
void free_split(char **split) 
{
	int i;
	
	i = -1;
	if (split == NULL || *split == NULL)
		return ;
	while (split[i]) {
		free(split[i]);
		i++;
	}
	free(split - 1);
}

void	error_free(t_stack_node **a, char **argv, bool flag_argc_2)
{
	free_stack(a);
	if (flag_argc_2)
		free_split(argv);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack_node **a)
{
    t_stack_node 	*current;
	t_stack_node	*aux;

    if (a == NULL)
		return ;
	current = *a;
	while (current)
	{
		aux = current->next;
		free(current);
		current = aux;
	}
	a = NULL;
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