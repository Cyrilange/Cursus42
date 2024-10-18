#include <unistd.h>

void ft_punbr(int nbr)
{
    char c;
    if (nbr > 9)
    {
        ft_punbr(nbr / 10);
        
    }
    c = (nbr % 10) + '0';
    write(1, &c, 1);
}

void fizz_buzz(int i)
{
    while (i >= 1 && i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            write(1, "fizzbuzz", 8);
        }
        else if (i % 5 == 0)
        {
            write(1, "buzz", 4);
        }
        else if (i % 3 == 0)
        {
            write(1, "fizz", 4);
        }
        else
        {
            ft_punbr(i);
        }
        write(1, "\n", 1);
        i++;
    }
}

int main(void)
{
    int n = 1;
    fizz_buzz(n);
    return (0);
}