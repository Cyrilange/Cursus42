/*
Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.*/

#include <unistd.h>

void    ft_putnbr(int n)
{
    char c;
    if (n > 9)
        ft_putnbr(n / 10);
    c = n % 10 + '0';
    write(1, &c, 1);
}

void    fizzbuzz(void)
{
    int n = 1;
    while (n >= 1 && n <= 100)
    {
        if (n % 3 == 0 && n % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if (n % 3 == 0)
            write(1, "fizz", 4);
        else if (n % 5 == 0)
            write(1, "buzz", 4);
        else
            ft_putnbr(n);
        write(1, "\n", 1);
        n++;
    }
}

int main(void)
{
    fizzbuzz();
    return 0;
}