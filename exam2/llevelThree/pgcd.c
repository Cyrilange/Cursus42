/*Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$i
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$*/

#include <stdlib.h>
#include <stdio.h>

int    ft_pgcd(int a, int b)
{
    int i = 1;
    int pgcd;
    while (i <= a && i <= b)
    {
        if (a % i == 0 && b % i == 0)
            pgcd = i;
        i++;
    }
    return pgcd;
}

int main(int argc, char **argv)
{
    int a;
    int b;
    
    if (argc == 3)
    {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        printf("%d", ft_pgcd(a, b));

    }
    printf("\n");
    return 0;
        
}