#include <stdio.h>
#include <stdlib.h>

void    fprime(unsigned int prime)
{
    int i = 2;
    if (prime <= 1)
    {
        printf("1");
        return;
    }
    while (prime >= i)
    {
        if (prime % i == 0)
        {
            printf("%d", i);
            prime /= i;
            if (prime > 1)
                printf("*");
        }
        else 
        {
            i++;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        fprime(atoi(argv[1]));
    }
    printf("\n");
    return (0);
}