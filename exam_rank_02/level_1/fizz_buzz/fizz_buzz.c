#include <unistd.h>

void    ft_putnbr(int n)
{
    char c;
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n > 9)
    {
        ft_putnbr(n / 10);
    }
    c = (n % 10) + '0';
    write(1, &c, 1);
}

void    fizz_buzz(int n)
{
    while (n >= 1 && n <= 100)
    {
        if (n % 3 == 0)
            write(1, "fizz", 4);
        else if (n % 5 == 0)
            write(1, "buzz", 4);
        else if (n % 3 == 0 && n % 5 == 0)
            write(1, "fizzbuzz", 8);
        else
            ft_putnbr(n);
        write(1, "\n", 1);
        n++;
    }
    
}

int main(void)
{
    int i = 1;
    fizz_buzz(i);
    //ft_putnbr(i);
    return (0);
}