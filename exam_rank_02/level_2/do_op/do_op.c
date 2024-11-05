#include "do_op.h"

int main(int argc, char **argv)
{
    if (argc != 4)  
    {
        printf("\n");
        return (1);
    }

    int num1 = atoi(argv[1]);
    char sign = argv[2][0];
    int num2 = atoi(argv[3]);
    int result;

    
    if (sign == '+')
    {
        result = num1 + num2;
    }
    else if (sign == '-')
    {
        result = num1 - num2;
    }
    else if (sign == '*')
    {
        result = num1 * num2;
    }
    else if (sign == '/')
    {
        if (num2 == 0)
        {
            printf("Erreur : division par zéro\n");
            return (1);
        }
        result = num1 / num2;
    }
    else if (sign == '%')
    {
        if (num2 == 0)
        {
            printf("Erreur : modulo par zéro\n");
            return (1);
        }
        result = num1 % num2;
    }
    else
    {
        printf("Erreur : opérateur invalide\n");
        return (1);
    }

    printf("%d\n", result);
    return (0);
}
