/*Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);

The  strdup() function returns a pointer to a new string which is a duplicate
of the string s.  Memory for the new string is obtained with  malloc(3), and
can be freed with free(3).

On success, the strdup() function returns a pointer to the duplicated string.
It returns NULL if insufficient memory was available, with errno set to indicate 
the cause of the error.*/
#include <stdlib.h>

char    *ft_strdup(char *src)
{
     int i = 0;
     int len;
     while (src[len])
        len++;
    char *new = malloc(sizeof(*new) * (len + 1));
    while (src[i])
    {
        new[i] = src[i];
        i++;
    }
    new[i] = '\0';
    return new;
}

#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        char *src = argv[1];
        char *dst = ft_strdup(src);
        printf("original : %s\n", src);
        printf("copy : %s", dst);
    }
    printf("\n");
    return 0;
}