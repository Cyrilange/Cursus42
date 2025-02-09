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

void	ft_error(t_stack_node **a, char **str, bool flag)
{
	free_stack(a);
	if (flag)
		free_split(str);
	write(1, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack_node **a)
{
	t_stack_node	*current;
	t_stack_node	*aux;

	if (!a)
		return ;
	current = *a;
	while (current)
	{
		aux = current->next;
		current->value = 0;
		free(current);
		current = aux;
	}
	*a = NULL;
}

void	free_split(char **str)
{
	int	i;

	i = -1;
	if (!str || *str == NULL)
		return ;
	while (str[i])
		free(str[i++]);
	free(str - 1);
}

void free_array(char **arr) {
    if (!arr)
        return;
    for (int i = 0; arr[i] != NULL; i++) {
        free(arr[i]);
    }
    free(arr);
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