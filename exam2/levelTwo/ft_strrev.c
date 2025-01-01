/*Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);*/

#include <unistd.h>

char    *ft_strrev(char *str)
{
    int i = 0;
    int len = 0;
    char aux;
    while (str[len])
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

//methode2

char    *ft_strrev2(char *str)
{
    char aux;
    char *start = str;
    char *end = str;
    while (*end)
        end++;
    end--;
    while (start < end)
    {
        aux = *start;
        *start = *end;
        *end = aux;
        start++;
        end--;
    }
    return (str);
}

int main(void)
{
    char str[5] = "hola";
    char str2[6] = "hello";

    // Print original string for method 1
    write(1, "original : ", 12);
    write(1, str, 5);
    write(1, "\n", 1);
    ft_strrev(str);
    write(1, "reverse : ", 11);
    write(1, str, 5);
    write(1, "\n", 1);

    // Print original string for method 2
    write(1, "\n", 1);
    write(1, "original methode 2 : ", 22);
    write(1, str2, 5);
    write(1, "\n", 1);
    ft_strrev2(str2);
    write(1, "reverse second method : ", 25);
    write(1, str2, 5);
    write(1, "\n", 1);

    return 0;
}