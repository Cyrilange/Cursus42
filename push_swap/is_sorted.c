#include "push_swap.h"

bool	is_sorted(t_stack_node *head)
{
	t_stack_node *current = head;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}