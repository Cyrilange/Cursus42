/*Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);*/

int	ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

/*

#include <stdio.h>

int main()
{
    char *str = "hola mundo";
    int n = ft_strlen(str);
    printf("%d", n);
    return 0;
}

*/