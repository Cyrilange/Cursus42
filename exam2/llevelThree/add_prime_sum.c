/*Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.
      
If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>*/

#include <unistd.h>


void    ft_putnbr(int n)
{
    char c;
    if (n > 9)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
    
}

int ft_atoi(char *str)
{
    int result = 0;
    int i = 0;
    while (str[i] >= '0' && str[i] <= '9')  
    {
        result = (result * 10) + (str[i] - '0');
        i++;
    }
        
    return result;
}

int is_prime(int n)
{
    int i = 2;
    if ( n < 2)
    return 0;
    while ( i * i <= n)
    {
        if ( n % i == 0)
            return 0;
        i++;
    }
    return 1;

}

int main(int argc, char **argv)
{
    

    if (argc == 2)
    {
        int i;
        int sum;
        i = ft_atoi(argv[1]);
        sum = 0;
        while (i > 0)
        {
            if(is_prime(i))
                sum += i;
            i--;
        }
        ft_putnbr(sum);
    }
    if (argc != 2)
        ft_putnbr(0);
    write(1, "\n", 1);
    return 0;
}