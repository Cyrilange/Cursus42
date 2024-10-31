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

void ft_putnbr(int n)
{
   char c;
   if (n > 9)
   {
    ft_putnbr(n / 10);
   }
   c = (n % 10) + '0';
   write(1, &c, 1);
}


int main(int argc, char **argv)
{
    int n = ft_atoi(argv[1]);
    int i = 1;
    if (argc != 2)
    {
        write(1, "\n", 1);
    }
    else
    {
        while (i <= 9 && n <= 238609183)
        {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(n);
            write(1, " = ", 3);
            ft_putnbr(n * i);
            write(1, "\n", 1);
            i += 1;       
            }
    }
    return (0);
}