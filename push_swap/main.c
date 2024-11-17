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
    t_stack_node *a;
    t_stack_node *b;
    
    a = NULL;
    b = NULL;
   

    if (argc < 2 || (argc == 2 && !argv[1][0]))
    {
        ft_putstr("Error\n");
        return (1);
    }
    else if (argc == 2)
        argv = ft_split(argv[1],' ');
    stack_init(&a,)
    if (!is_sorted(&a))
    {
        if (stack_len(&a) == 2)
            sa(&a, 1);
        else if (stack_len(&a) == 3)
            sort_small(&a);
        /*else
			push_swap(&a, &b);*/
    }
    return (0);
}
