/*Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);*/

void    ft_swap(int *a, int *b)
{
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;

}
/*
#include <unistd.h>
//small putnbr
void ft_putnbr(int n) {
    char c = n + '0';
    write(1, &c, 1);
}

int main(void)
{
    int a = 9;
    int b = 5;

   write(1, "Avant l'échange :\n", 19);
    ft_putnbr(a);
    write(1, "\n", 1);
    ft_putnbr(b);
    write(1, "\n", 1);

   
    ft_swap(&a, &b);

  
    write(1, "Après:\n", 8);
    ft_putnbr(a);
    write(1, "\n", 1);
    ft_putnbr(b);
    write(1, "\n", 1);

    return (0);
}
*/