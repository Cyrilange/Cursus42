#include <stdio.h>
#include <stdlib.h>

char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        c = c +'a' - 'A';
    }
    return (c);
}

int get_digits(char c, int base_v)
{
    int max;
    if (base_v <= 10)
    {
        max = base_v - 1 + '0';
    }
    else
    {
        max = base_v - 10 - 1 + 'a';
    }
    if (c >= '0' && c <= '9' && c <= max)
    {
        return (c - '0');
    }
    else if (c >= 'a' && c <= 'f' && c <= max)
    {
        return (10 + ('c' - 'a'));
    }
    else
    {
        return (-1);
    }
}

int	ft_atoi_base(const char *str, int str_base)
{
    int result = 0;
    int sign = 1;
    int digits;
    if (str_base < 2 || str_base > 16)
        return (0);
    if (*str == '-')
    {
        sign = -1;
        ++str;
    }
    
    while (*str)
    {
        digits = get_digits(to_lower(*str), str_base);
        if (digits == -1)
            break;
        result = result * str_base + digits;
        ++str;
    }
    return (result * sign);
}

int main(int argc, char **argv)
{
    int base = atoi(argv[2]);
    if (argc == 3)
    {
        int res = ft_atoi_base(argv[1], base);
        printf("%d", res);
    }
    printf("\n");
    return (0);
}