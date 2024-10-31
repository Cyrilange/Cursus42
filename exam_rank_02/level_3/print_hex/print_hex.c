#include <unistd.h>

int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;
    while (str[i])
    {
        result = (result * 10) + (str[i] - '0');
        i++;
    }
    return (result);
}

void print_hex(unsigned long long n)
{
    char *c;
    
    c = "0123456789abcdef";
    if (n >= 16)
    {
       print_hex(n / 16);
    }
    write(1, &c[n % 16], 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        print_hex(ft_atoi(argv[1]));
        write(1, "\n", 1);
        return (1);
    }
    write(1, "\n", 1);
    return (0);
}