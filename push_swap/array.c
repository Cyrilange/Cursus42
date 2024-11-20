/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-20 15:24:27 by csalamit          #+#    #+#             */
/*   Updated: 2024-11-20 15:24:27 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_sorted_array(t_stack_node *stack, int size)
{
    int				*array;
    t_stack_node	*current;
    int				i;

    if (size <= 0 || !stack)
        return (NULL);
    array = malloc(size * sizeof(int));
    if (!array)
        return (NULL);
    current = stack;
    i = 0;
    while (current && i < size)
    {
        array[i] = current->value;
        current = current->next;
        i++;
    }
    if (i != size)
    {
        free(array);
        ft_error(1);
    }
    quicksort(array, 0, size - 1);
    return (array);
}


void	quicksort(int *arr, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high);
		quicksort(arr, low, pivot - 1);
		quicksort(arr, pivot + 1, high);
	}
}

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	aux;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			aux = arr[i];
			arr[i] = arr[j];
			arr[j] = aux;
		}
		j++;
	}
	aux = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = aux;
	return (i + 1);
}
