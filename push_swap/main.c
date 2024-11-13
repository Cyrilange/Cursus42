#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_node *a = NULL;  // Pile A
    t_stack_node *b = NULL;  // Pile B
    int i = 1;

    // Vérifier si le nombre d'arguments est valide
    if (argc < 2)
    {
        ft_putstr("Error\n");
        return (1);
    }

    // Ajouter les arguments dans la pile a
    while (i < argc)
    {
        if (!is_valid_integer(argv[i]))  // Vérifier si l'argument est un entier valide
        {
            ft_putstr("Error\n");
            return (1);
        }
        push_to_stack(&a, ft_atoi(argv[i]));  // Ajouter l'argument à la pile a
        i++;
    }

    // Vérifier les doublons dans la pile a
    if (is_duplicate(a))
    {
        ft_putstr("Error\n");
        return (1);
    }

    // Vérifier si la pile est déjà triée
    if (is_sorted(a))
    {
        ft_putstr("OK\n");
    }
    else
    {
        // Si non triée, effectuer le tri en fonction du nombre d'éléments
        if (stack_len(&a) == 2)
            sort_two_numbers(&a);
        else if (stack_len(&a) == 3)
            sort_three_numbers(&a);
        else if (stack_len(&a) == 4)
            sort_four_numbers(&a, &b);
        else if (stack_len(&a) == 5)
            sort_five_numbers(&a, &b);
      //  else
        //    push_swap(&a, &b);  // Trie avec un grand nombre d'éléments
    }

    return (0);
}
