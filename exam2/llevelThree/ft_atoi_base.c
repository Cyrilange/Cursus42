/*Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);*/

int	ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int result = 0;
    int sign = 1;
    if (str_base < 2 || str_base > 16)
        return 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    while (str[i] == '+' || str[i] == '-')
    {
    if (str[i] == '-')
        sign *= -1;
    i++;
    }
    while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F'))
    {
        int value;
        if (str[i] >= '0' && str[i] <= '9')
            value =  str[i] - '0';
        if (str[i] >= 'a' && str[i] <= 'f')
            value = ((str[i] - 'a') + 10);
        if (str[i] >= 'A' && str[i] <= 'F')
            value = ((str[i] - 'A') + 10);
        if (value >= str_base)
            return 0;
        result = (result * str_base) + value;
        i++;
    }
    return (result * sign);
}

#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 3)
        {
            int base = ft_atoi_base(argv[2], 10);
            int result = ft_atoi_base(argv[1], base);
            printf("%d", result);
        }
    printf("\n");
    return 0;
}
