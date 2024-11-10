#include <push_swap.h>

int	main(int argc, char **argv)
{
	int				i;
	int				j;
	t_stack_node	*head;
	char			**args;
	if (argc < 2) // if less than 2 arguments we return error
		ft_putstr("Error\n");
	t_stack_node *head = NULL;
	**args = argv + 1;
	if (!check_no_error(head, args)) // if we find an error we return error
		ft_putstr("Error\n");
	else  // no error so we can now chack hoe many arguments we have
	{
		if  (is_sorted(head))
			ft_putstr("OK\n");
		else if (argc - 1 == 2)
			sort_two_numbers(head);
		else if (argc - 1 == 3)
			sort_three_number(head);
		else if (argc - 1 == 4)
			sort_four_number(head);
		else if (argc - 1 == 5)
			sort_five_numbers(head);
		else 
			push_swap(head); */
	}
	return (0);
}