
char *ft_rev(char *str)
{
    char *start = str;
    char *end = str;
    while (*end)
        end++;
    end--;
    char temp;
    while (start < end)
    {
        temp = *end;
        *end = *start;
        *start = temp;
        start++;
        end--;
    }
    return str;
}


#include <stdio.h>
int main(int argc, char **argv)
{
    printf("%s", ft_rev(argv[1]));
    return 0;

}