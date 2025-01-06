/*
int     *ft_range(int start, int end);
It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:
  - With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/
#include <stdio.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int i = 0;
    int len;
    int *range;

    if (start < end)
        len = end - start + 1;
    else
        len = start - end + 1;
    range = malloc(len *sizeof(int));
    if (!range)
        return NULL;
    while (i < len)
    {
        if (start < end)
            range[i] = start + i;
        else
            range[i] = start - i;
        i++;
    }
    return range;
}

int main()
{
    int i = 0;
    int len;
    int *range;
    int start = -1;
   int end = -9;
    if (start < end)
        len = end - start + 1;
    else
        len = start - end + 1;
   range = ft_range(start, end);
   while (i < len)
   {
    printf ("%d", range[i]);
    i++;
   }
   free(range);
   return 0;
}