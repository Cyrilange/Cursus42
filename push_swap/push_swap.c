#include "push_swap.h"

void push_swap(t_stack_node **stack_a, t_stack_node **stack_b)
{
    int stack_size;

    stack_size = stack_len(stack_a);
    if (stack_size <= 3)
        sort_small(stack_a);
    else if (stack_size <= 5)
        sort_five(stack_a, stack_b);
    else
        sort_large(stack_a, stack_b, stack_size);
}

void sort_large(t_stack_node **stack_a, t_stack_node **stack_b, int size)
{
    int num_chunks;
    if (size <= 100)
        num_chunks = 5;
    else
        num_chunks = 10;
    
    int *sorted_array = create_sorted_array(*stack_a, size);
    int chunk_size = size / num_chunks;

    int i = 0;
    while (i < num_chunks)
    {
        int min = sorted_array[i * chunk_size];
        int max = sorted_array[(i + 1) * chunk_size - 1];

        push_chunk_to_b(stack_a, stack_b, min, max);
        i++;
    }

    sort_b(stack_a, stack_b);
    free(sorted_array);
}


