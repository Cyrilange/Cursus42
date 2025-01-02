/*Reproduce exactly the behavior of the strspn function 
(man strspn).
The function should be prototyped as follows:
size_t	ft_strspn(const char *s, const char *accept);
DESCRIPTION:
The function calculates the length (in bytes) of the initial
segment of s which consists entirely of bytes in accept.

RETURN VALUE:
The function returns the number of bytes in the initial seg‐
ment of s which consist only of bytes from accept.*/

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
    size_t i = 0;
    size_t j;
    int count ;
    while (s[i])
    {
        count = 0;
        j = 0;    
        while (accept[j])
        {
            if (s[i] == accept[j])
                count = 1;
                break ;
        
            j++;
        }
        if (!count)
            break;
        i++;
    }
    return i;
}

int main (int argc, char *argv[])
{
    if (argc != 3)
        fprintf(stderr, "Uso: %s <cadena 1> <cadena 2>\n", argv[0]);
    else
    {
        printf("El número de caracteres coincidentes es: %zu\n", ft_strspn(argv[1], argv[2]));
        printf("El resultado de la función original es : %zu\n", ft_strspn(argv[1], argv[2]));
    }
    return (0);
} 