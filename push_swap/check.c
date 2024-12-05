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

bool	ft_is_digit(char n)
{
	if (n >= '0' && n <= '9')
		return (true);
	return (false);
}
int is_valid_integer(char *str)
{
    long n;
    int i = 0;

    // Gérer le signe '-' au début
    if (str[i] == '-' || str[i] == '+')
        i++;

    // Vérifier si les caractères suivants sont des chiffres
    while (str[i] && ft_is_digit(str[i]))
        i++;

    // Si on a atteint la fin de la chaîne et qu'il y a des chiffres
    if (str[i] != '\0')
        return (0);

    // Convertir en entier long (et vérifier si ça dépasse la plage des entiers)
    n = ft_atol(str);

    // Vérifier si le nombre est dans la plage des entiers
    if (n > INT_MAX || n < INT_MIN)
        return (0);

    return (1);
}


int	is_duplicate(t_stack_node *head, long value)
{
	t_stack_node	*aux;

	aux = head;
	while (aux != NULL)
	{
		if (aux->value == value)
			return (1);
		aux = aux->next;
	}
	return (0);
}


void	stack_checked(t_stack_node **head, char **argv)
{
	long			n;
	int				i;
	t_stack_node	*new_node;
	t_stack_node	*current;

	i = 1;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		printf("Processing: %s -> %ld\n", argv[i], n); 
		if (!is_valid_integer(argv[i]))
		{
			ft_error(true, head, NULL);
		}
		if (is_duplicate(*head, n))
		{
			ft_error(true, head, NULL);
		}
		new_node = create_node(n);
		if (!*head)  // Si la liste est vide
		{
			*head = new_node;  // Le nouveau nœud devient le premier nœud
			printf("Created first node: %ld\n", n);
		}
		else  // Sinon, on ajoute à la fin de la liste
		{
			current = *head;
			while (current->next)  // Trouver le dernier nœud
				current = current->next;
			current->next = new_node;  // Ajouter à la fin
			new_node->prev = current;  // Lier à l'ancien dernier nœud
			printf("Added new node: %ld\n", n);
		}
		i++;
	}
}
