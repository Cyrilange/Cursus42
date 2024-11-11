//ra rb rr
#include "push_swap.h"

void	ra(t_stack_node **stack_a, int print)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if(!*stack_a || !(*stack_a)->next)
		return ;
	first =  *stack_a;
	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	second = *stack_a;
	while(second->next)
		second = second->next;
	second->next = first;
	first->prev = second;
	first->next = NULL;
	if (print == 1)
		ft_putstr("ra\n");
}

void	rb(t_stack_node **stack_b, int print)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if(!*stack_b || !(*stack_b)->next)
		return ;
	first =  *stack_b;
	*stack_b = first->next;
	(*stack_b)->prev = NULL;
	second = *stack_b;
	while(second->next)
		second = second->next;
	second->next = first;
	first->prev = second;
	first->next = NULL;
	if (print == 1)
		ft_putstr("rb\n");
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, int print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print)
		ft_putstr("rr\n");
}
