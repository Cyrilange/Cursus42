#include <unistd.h>

char    *ft_strrev(char *str)
{
    char aux;
    int i = 0;
    int len = 0;

    while(str[len])
        len++;
    while (i < (len / 2))
    {
        aux = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = aux;
        i++;
    }
    return (str);
}

#include <stdio.h>

int main (int argc, char *argv[])
{
    if (argc != 2)
        fprintf (stderr, "Uso: %s <cadena para invertir>\n", argv[0]);
    else
    {
        printf ("La cadena original es: %s\n", argv[1]);
        printf ("La cadena invertida es: %s\n", ft_strrev(argv[1]));
    }
    return (0);
}