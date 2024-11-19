#include "push_swap.h"

int get_position(t_stack_node *stack, t_stack_node *target)
{
    int position = 0;

    while (stack && stack != target)
    {
        stack = stack->next;
        position++;
    }
    return position;
}

t_stack_node *find_max_node(t_stack_node *stack)
{
    t_stack_node *current = stack;
    t_stack_node *max_node = stack;

    while (current)
    {
        if (current->value > max_node->value)
            max_node = current;
        current = current->next;
    }
    return max_node;
}

t_stack_node *find_min_node(t_stack_node *stack)
{
    t_stack_node *current = stack;
    t_stack_node *min_node = stack;

    while (current)
    {
        if (current->value < min_node->value)
            min_node = current;
        current = current->next;
    }
    return min_node;
}