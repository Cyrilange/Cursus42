/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-24 19:27:21 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-24 19:27:21 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	stack_size;

	stack_size = stack_len(stack_a);
	if (stack_size == 3)
		sort_small(stack_a);
	else
		sort_large(stack_a, stack_b, stack_size);
}

void	sort_large(t_stack_node **stack_a, t_stack_node **stack_b, int size)
{
	int				*sorted_array;
	int				i;
	t_sort_large	num;

	if (size > 5 && size <= 100)
		num.num_chunks = 3;
	else
		num.num_chunks = 10;
	sorted_array = create_sorted_array(*stack_a, size);
	num.chunk_size = size / num.num_chunks;
	i = 0;
	while (i < num.num_chunks)
	{
		num.min = sorted_array[i * num.chunk_size];
		num.max = sorted_array[(i + 1) * num.chunk_size - 1];
		push_chunk_to_b(stack_a, stack_b, num.min, num.max);
		i++;
	}
	sort_b(stack_a, stack_b);
	free(sorted_array);
}
