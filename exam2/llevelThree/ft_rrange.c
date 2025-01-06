/*Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.*/

#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
    int i = 0;
    int *array;
    int len;

    if (start < end)
        len = end - start  + 1;
    else
        len = start - end + 1;
    array = malloc(len *sizeof(int));
    while (i < len)
    {
        if (start < end)
            array[i] = end - i;
        else
            array[i] = end + i;
        i++; 
    }
    return array;

}
#include <stdio.h>
int main()
{
    int start = -6;
    int end = 6;
    int len;
    int i = 0;
    if (start < end)
        len = end - start  + 1;
    else
        len = start - end + 1;
    int *result = ft_rrange(start, end);

    while (i < len)
    {
        printf("%d ", result[i]);
        i++;
    }
    printf("\n");
    return 0;
}