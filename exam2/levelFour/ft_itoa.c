#include <stdio.h>
#include <stdlib.h>

int nlen(int n)
{
    int len = 0;
    if (n < 0)
    {
        n *= -1;
        len++;
    }
    if (n == 0)
        len++;
    while (n)
    {
        n /= 10;
        len++;
    }
    return len;
}

char	*ft_itoa(int nbr)
{
    int len = nlen(nbr);
    long n = nbr;
    char *str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return NULL;
    str[len] = '\0';
    if (n < 0)
    {
        *str = '-';
        n *= -1;
    }
    if (n ==  0)
        *str = '0';
    while (n)
    {
        *(str + len - 1) = n % 10 + '0';
        n /= 10;
        len--;
    }
    return str;
    

}

#include <stdio.h>

int	main(void)
{
	int 	n = -123;
	char	*value = ft_itoa(n);

	printf("Conversion successful if %s is the same as %d\n", value, n);
	return (0);
}