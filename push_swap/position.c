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

void    move(t_stack_node **stack_a, t_stack_node **stack_b, int cost_a, int cost_b)
{
    while (cost_a < 0 && cost_b < 0)
        {
			rra(stack_a, 1);
			rrb(stack_b, 1);
			cost_a++;
			cost_b++;
		}
    while (cost_a > 0 && cost_b > 0)
        {
			ra(stack_a, 1);
			rb(stack_b, 1);
			cost_a--;
			cost_b--;
		}
	while (cost_a-- > 0)
		ra(stack_a, 1);
	while (cost_a++ < 0)
		rra(stack_a, 1);
	while (cost_b-- > 0)
		rb(stack_b, 1);
	while (cost_b++ < 0)
		rrb(stack_b, 1);
    pa(stack_a, stack_b, 1);
}

void	move_index_to_stack_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
    int	max;
    int	len;
    int	i;

    len = stack_len(stack_a);
    max = len / 2;
	i = 0;
	while (i < len)
    {
		if ((*stack_a)->index <= max)
			pb(stack_a, stack_b, 1);
        else
			ra(stack_a, 1);
		i++;
    }
}
