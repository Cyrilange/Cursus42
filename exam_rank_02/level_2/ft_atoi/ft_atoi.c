/*Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);*/
#include <unistd.h>

void    ft_putnbr(int n)
{
    char c;
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n > 9)
    {
        ft_putnbr(n / 10);
    }
    c = (n % 10) + '0';
    write(1, &c, 1);
}

int	ft_atoi(const char *str)
{
    int result = 0;
    int i = 0;
    int sign = 1;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - '0');
        i++;
    }

    return (result * sign);
}

int main(void)
{
    char nbr[] = "   +++-----1234";
    int c = ft_atoi(nbr);
    ft_putnbr(c);
    write(1, "\n", 1);
    return (0);
}