/*Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);


DESCRIPTION
The strpbrk() function locates the first occurrence in the string s of any of the bytes in the string accept.

RETURN VALUE
The strpbrk() function returns a pointer to the byte in s that matches one of the bytes in accept, or NULL if no such byte is found.*/
#include <unistd.h>

char    *ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;
    int j;
    if (!s1 || !s2)
    {
        return (0);
    }
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            while (s1[i] == s2[j])
            {
                return ((char*) &s1[i]);
            }
            j++;
        }
        i++;
    }
    return NULL;
}
/*
#include <stdio.h>

int main (int argc, char *argv[])
{
    if(argc != 3)
    {
        fprintf (stderr, "Uso: %s <cadena> <caracteres>\n", argv[0]);
        return 1;
    }
    char *resultado = ft_strpbrk(argv[1], argv[2]);
    if(resultado)
        printf("El primer caracter encontrado es %s en la posición %ld.\n", resultado, resultado - argv[1]);
    else
        printf("Ninguno de los resultados de %s se encontro en %s.\n", argv[1], argv[2]);
    return (0);
} */