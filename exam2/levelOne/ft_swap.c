/*Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);*/

void	ft_swap(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;

}

#include <stdio.h>

int main(void)
{
    int a = 5;
    int b = 9;
    printf("before swap:  %d, %d\n", a, b);
    ft_swap(&a, &b);
    printf("after swap :  %d, %d\n", a, b);
    return 0;
}