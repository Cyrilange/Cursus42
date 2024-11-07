/*Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);

DESCRIPTION
       The strcspn() function calculates the length of the initial segment of s which consists entirely of bytes not in reject.
RETURN VALUE
       The strcspn() function returns the number of bytes in the initial segment of s which are not in the string reject.
*/

#include <unistd.h>
#include <stdarg.h>

void ft_putnbr(int n)
{
    char c;
    if (n > 9)
    {
        ft_putnbr(n / 10);
    }
    c = n % 10 + '0';
    write(1, &c, 1);
}

size_t ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;
    size_t j;

    while (s[i] != '\0')
    {
        j = 0;
        while (reject[j] != '\0')
        {
            if (s[i] == reject[j])
            {
                return (i);
            }
            j++;
        }
        i++;
    }
    return (i);
}

int main()
{
    char *s1 = "bonjour";
    char *s2 = "caiujurdhui";
    size_t a = ft_strcspn(s1, s2);
    ft_putnbr(a); 
    write(1, "\n", 1);

    char *s3 = "hello world";
    char *s4 = "l";
    size_t b = ft_strcspn(s3, s4);
    ft_putnbr(b);
    write(1, "\n", 1);

    return 0;
}
