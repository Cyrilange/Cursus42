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

    if (argc < 2 || argc == 2)
        return(1);
    else
    {
        stack_checked(&a, argv + 1);
        if (!is_sorted(&a))
        {
            if (stack_len(&a) == 2)   // tested and works
                sa(&a, 1);
            else if (stack_len(&a) == 3)  // tested and works
                sort_small(&a);
            else if (stack_len(&a) == 5)
                sort_five(&a, &b);  //tested and works
            /*else
                push_swap(&a, &b); */  // does not work yet , must be something creating a inf loop
        } 
        else
            write(1,"OK\n",3);
    }

    free_both(&a, &b);
}