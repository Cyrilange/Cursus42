#include "push_swap.h"
#include <unistd.h>

bool	ft_is_digit(int	n)
{
	    if (n >= '0' && n <= '9')
			return (true);
		return (false);
}

bool	is_valid_integer(char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while(str[i])
	{
		if(!ft_is_digit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_duplicate(t_stack_node *head)
{
	t_stack_node *current = head;
	while (current != NULL)
	{
		t_stack_node *check = current->next;
		while (check != NULL)
		{
			if (current->value == check->value)
				return (true);
			check = check->next;
		}
		current = current->next;
	}
	return (false);
}

bool	check_no_error(t_stack_node *head, char	**args)
{
	int	i;
	int	j;

	i = 0;
	if (is_duplicate(head))
		return (false);
	while (args[i])
	{
		if (!is_valid_integer(args[i]))
			return (false);
		j = 0;
		while (args[i][j])
		{
			if (!ft_is_digit(args[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    // Vérifie que l'on a bien un argument
    if (argc < 2)
    {
        write(1, "Error: No arguments provided\n", 28);
        return (0);
    }

    // Test de ft_is_digit
    if (ft_is_digit(argv[1][0]))  // Tester le premier caractère du premier argument
        write(1, "ft_is_digit: true\n", 18);
    else
        write(1, "ft_is_digit: false\n", 19);

    // Test de is_valid_integer
    if (is_valid_integer(argv[1]))  // Tester l'intégralité du premier argument
        write(1, "is_valid_integer: true\n", 23);
    else
        write(1, "is_valid_integer: false\n", 24);

    // Test de is_duplicate (on crée une pile pour les tests)
    t_stack_node *head = NULL;
    t_stack_node *node1 = malloc(sizeof(t_stack_node));
    node1->value = atoi(argv[1]);
    node1->next = NULL;
    head = node1;

    // Ajoute un doublon pour tester is_duplicate
    t_stack_node *node2 = malloc(sizeof(t_stack_node));
    node2->value = atoi(argv[1]);
    node2->next = NULL;
    node1->next = node2;  // Ajout d'un doublon

    if (is_duplicate(head))  // Test avec doublon
        write(1, "is_duplicate: true\n", 20);
    else
        write(1, "is_duplicate: false\n", 21);

    // Libère la mémoire de la pile
    free(node2);
    free(node1);

    return (0);
}
