#include "push_swap.h"

void	sa(t_stack_node **stack_a, int print)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if(!*stack_a || !(*stack_a)->next)
		return (0);
	first =  *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	*stack_a = second;

	if (print == 1)
		ft_putstr("sa\n");
}

void	sb(t_stack_node **stack_b, int print)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if(!*stack_b || !(*stack_b)->next)
		return (0);
	first =  *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	*stack_b = second;

	if (print == 1)
		ft_putstr("sb\n");
}