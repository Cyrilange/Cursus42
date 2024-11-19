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

int main(int argc, char **argv)
{
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;

    if (argc < 2 || (argc == 2 && !argv[1][0]))
        ft_error(1);
    else
    {
        stack_checked(&a, argv + 1); // Ignore le nom du programme
        if (!is_sorted(&a))
        {
            if (stack_len(&a) == 2)
                sa(&a, 1);
            else if (stack_len(&a) == 3)
                sort_small(&a);
            else
                push_swap(&a, &b); // Implémente une logique pour les cas plus grands
        }
        else
            write(1,"OK\n",3);
    }

    free_both(&a, &b); // Libère les deux piles
    return (0);
}
