/*size_t	ft_strcspn(const char *s, const char *reject);

The strcspn() function calculates the length of the initial  
segment of s which consists entirely of bytes not in reject.

The strcspn() function returns the number of bytes in the 
initial segment of s which are not in the string reject.*/

#include <stdlib.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;
    size_t j;
    while (s[i])
    {
        j = 0;
        while (reject[j])
        {
            if (s[i] == reject[j])
                return i;
            j++;
        }
        i++;
    }
    return i;
}

// test to check the function 


#include <stdio.h>


int main()
{
    char s[15] = "hello";
    char reject[15] = "o";
    char s1[15] = "hello";
    char reject1[15] = "h";
    char s2[15] = "hello";
    char reject2[15] = "";
    int i = ft_strcspn(s, reject);
    int j = ft_strcspn(s1, reject1);
    int k = ft_strcspn(s2, reject2);
    printf("%d", i);
    printf("\n");
    printf("%d\n", j);
    printf("%d\n", k);
    return 0;

}