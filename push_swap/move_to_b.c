#include "push_swap.h"

void push_chunk_to_b(t_stack_node **stack_a, t_stack_node **stack_b, int min, int max)
{
    t_stack_node *current;

    while ((current = find_in_range(*stack_a, min, max)) != NULL)
    {
        move_to_top(stack_a, current); // Amène l’élément dans la plage au sommet
        pb(stack_a, stack_b, 1);      // Pousse-le dans B
    }
}

t_stack_node *find_in_range(t_stack_node *stack, int min, int max)
{
    while (stack)
    {
        if (stack->value >= min && stack->value <= max)
            return stack;
        stack = stack->next;
    }
    return NULL;
}

void sort_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
    while (*stack_b)
    {
        t_stack_node *max_node = find_max_node(*stack_b); // Trouve le plus grand élément
        move_to_top(stack_b, max_node);                  // Amène-le au sommet de B
        pa(stack_a, stack_b, 1);                         // Pousse-le dans A
    }
}


