/*Write the following function:
int		max(int* tab, unsigned int len);
The first parameter is an array of int, the second is the number of elements in
the array.
The function returns the largest number found in the array.
If the array is empty, the function returns 0.*/

int		max(int* tab, unsigned int len)
{
    int i = 0;
    int result;
    if (tab[i] == '\0')
        return 0;
    while (i < len)
    {
        if (tab[i] > result)
            result = tab[i];
        i++;
    }
    return result;
}

#include <stdio.h>

int main(void)
{
    int array[5] = {4, 21, 7, 9, 0};
    printf("%d\n", max(array, 5));
    int arr[7] = {4, 2, 7, 9, 0, 12, 3};
    printf("%d\n", max(arr, 7));
    return 0;
}