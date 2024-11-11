//rra rrb rrr
#include "push_swap.h"

void	rra(t_stack_node **stack_a, int print)
{
	t_stack_node	*last;
	t_stack_node	*before_last;

	if(!*stack_a || !(*stack_a)->next)
		return ;
	last =  *stack_a;
	while(last->next)
	{
        before_last = last;
        last = last->next;
    }
	before_last->next = NULL;
	last->prev = NULL;
	last->next = *stack_a;
    (*stack_a)->prev = last;
    *stack_a = last;
	if (print == 1)
		ft_putstr("rra\n");
}

void	rrb(t_stack_node **stack_b, int print)
{
	t_stack_node	*last;
	t_stack_node	*before_last;

	if(!*stack_b || !(*stack_b)->next)
		return ;
	last =  *stack_b;
	while(last->next)
	{
        before_last = last;
        last = last->next;
    }
	before_last->next = NULL;
	last->prev = NULL;
	last->next = *stack_b;
    (*stack_b)->prev = last;
    *stack_b = last;
	if (print == 1)
		ft_putstr("rrb\n");
}


void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, int print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print)
		ft_putstr("rrr\n");
}

