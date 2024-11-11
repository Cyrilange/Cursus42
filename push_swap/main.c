#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_node *stack_a = NULL;
    t_stack_node *stack_b = NULL;
    int i;

	i = 1;
    if (argc < 2)
    {
        ft_putstr("Error\n");
        return (0);
    }
    while (i++ < argc)
    {
        if (!is_valid_integer(argv[i]))
        {
            ft_putstr("Error\n");
            return (0);
        }
        push_to_stack(&stack_a, ft_atoi(argv[i]));
    }
    if (is_duplicate(stack_a))
    {
        ft_putstr("Error\n");
        return (0);
    }
    if (is_sorted(stack_a))
    {
        ft_putstr("OK\n");
        return (0);
    }
    if (argc - 1 == 2)
        sort_two_numbers(&stack_a);
    else if (argc - 1 == 3)
        sort_three_numbers(&stack_a);
    else if (argc - 1 == 4)
        sort_four_numbers(&stack_a, &stack_b);
    else if (argc - 1 == 5)
        sort_five_numbers(&stack_a, &stack_b);
    if (is_sorted(stack_a))
        ft_putstr("OK\n");
    return (0);
}
