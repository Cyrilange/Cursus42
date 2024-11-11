#include "push_swap.h"

int sort_two_numbers(t_stack_node **head)
{
    if (! *head || ! (*head)->next )
        return (0);
    if (((*head)->value > (*head)->next->value))
        sa(head, 1);
    return (1);   
}

void sort_three_numbers(t_stack_node **stack_a)
{
    int first = (*stack_a)->value;
    int second = (*stack_a)->next->value;
    int third = (*stack_a)->next->next->value;

    if (first > second && second < third && first < third)
        sa(stack_a, 1);
    else if (first > second && second > third)
    {
        sa(stack_a, 1);
        rra(stack_a, 1);
    }
    else if (first > second && second < third && first > third)
        ra(stack_a, 1);
    else if (first < second && second > third && first < third)
    {
        sa(stack_a, 1);
        ra(stack_a, 1);
    }
    else if (first < second && second > third && first > third)
        rra(stack_a, 1);
}

void sort_four_numbers(t_stack_node **stack_a, t_stack_node **stack_b)
{
    int min_pos = find_min_position(*stack_a);

    if (min_pos == 1)
        sa(stack_a, 1);
    else if (min_pos == 2)
    {
        ra(stack_a, 1);
        ra(stack_a, 1);
    }
    else if (min_pos == 3)
        rra(stack_a, 1);
    pb(stack_a, stack_b, 1);
    sort_three_numbers(stack_a);
    pa(stack_a, stack_b, 1);
}

void sort_five_numbers(t_stack_node **stack_a, t_stack_node **stack_b)
{
    int min_pos;

    min_pos = find_min_position(*stack_a);
    move_to_top(stack_a, min_pos);
    pb(stack_a, stack_b, 1);
    min_pos = find_min_position(*stack_a);
    move_to_top(stack_a, min_pos);
    pb(stack_a, stack_b, 1);
    sort_three_numbers(stack_a);
    pa(stack_a, stack_b, 1);
    pa(stack_a, stack_b, 1);
}
