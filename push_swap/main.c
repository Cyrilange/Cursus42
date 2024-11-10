#include <push_swap.h>

int	main(int argc, char **argv)
{
	int				i;
	int				j;
	t_stack_node	*head;
	char			**args;
	if (argc < 2) // if less than 2 arguments we return error
		ft_putstr("Error");
	t_stack_node *head = NULL;
	**args = argv + 1;
	if (!check_no_error(head, args)) // if we find an error we return error
		ft_putstr("Error");
	else  // no error so we can now chack hoe many arguments we have
	{
		/*if  it is already sorted;
			print ok;
		else if we only have 2 numbers
			function 2 numbers.
		else if we only have 3 numbers
			function 3 numbers;
		else if we only have 5 numbers;
			function 5 numbers;
		else 
			do the push swap function; */
	}
	return (0);
}