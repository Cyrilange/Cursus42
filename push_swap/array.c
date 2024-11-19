#include "push_swap.h"

int *create_sorted_array(t_stack_node *stack, int size)
{
    int *array = malloc(size * sizeof(int));
    if (!array)
        ft_error(1);

    t_stack_node *current = stack;
    for (int i = 0; current; i++)
    {
        array[i] = current->value;
        current = current->next;
    }

    quicksort(array, 0, size - 1); // Trie le tableau avec un algorithme rapide
    return array;
}

void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}
