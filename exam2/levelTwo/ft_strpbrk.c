/*Reproduce exactly the behavior of the function strpbrk
(man strpbrk).
The function should be prototyped as follows:
char	*ft_strpbrk(const char *s1, const char *s2);

DESCRIPTION:
The  strpbrk() function locates the first occurrence in the 
string s1 of any of the bytes in the string s2.

RETURN VALUE:
The strpbrk() function returns a pointer to the byte in s that 
matches one of the bytes in s2, or NULL if no such byte is 
found.*/
#include <unistd.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;
    int j;
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
                return ((char*) &s1[i]);
            j++;
        }
        i++;
    }
    return NULL;
}

#include <stdio.h>

int main (int argc, char *argv[])
{
    if(argc != 3)
    {
        return 1;
    }
    char *result = ft_strpbrk(argv[1], argv[2]);
    if(result)
        printf("first char is : %s,  in position %ld.\n", result, result - argv[1]);
    else
        printf("no resultat %s found in %s.\n", argv[1], argv[2]);
    return (0);
}