#include "push_swap.h"

int find_min_position(t_stack_node *stack)
{
    int min_position = 0;
    int current_position = 0;
    int min_value;
    t_stack_node *current = stack;

    if (!stack)
        return -1;

    min_value = current->value;
    
    while (current != NULL)
    {
        if (current->value < min_value)
        {
            min_value = current->value;
            min_position = current_position;
        }
        current_position++;
        current = current->next;
    }

    return min_position;
}

void move_to_top(t_stack_node **stack, int position) 
{
    while (position > 0) {
        ra(stack, 1);
        position--;
    }
    while (position < 0) {
        rra(stack, 1);
        position++;
    }
}