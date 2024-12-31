/*Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);*/

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    while (s1[i])
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}
/*
#include <stdio.h>

int main(void)
{
    char src[4] = "hola";
    char dst[4] = "";
    ft_strcpy(src, dst);
    printf("%s\n", &dst);
    return 0;

}
*/