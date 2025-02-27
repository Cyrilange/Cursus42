#include <unistd.h>
#include <stdarg.h>


int my_putstr(char *str, int i)
{
    if (!str)
        return my_putstr("(null)", i);
    if (!str[i])
        return i;
    write(1, &str[i], 1);
    return my_putstr(str, i + 1);
}

int    my_number(long n , int base)
{
    char *str = "0123456789abcdef";
    if (n < 0 && base == 10)
        return write(1, "-", 1) + my_number(n* -1, base);
    if (n < 0 && base == 16)
        return my_number((unsigned int)n, base);
    if (n / base == 0)
        return write(1,&str[n % base], 1);
    return my_number(n / base, base) + my_number(n % base, base);
}

int parse_string(char *str, va_list args)
{
    int count = 0;
    int i = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 's')
                count += my_putstr(va_arg(args, char *), 0);
            if (str[i] == 'd')
                count += my_number(va_arg(args, int), 10);
            if (str[i] == 'x')
                count += my_number(va_arg(args, int), 16);
        }
        else
            write(1, &str[i], 1);
        i++;
    }
    return count;
}

int my_printf(char *str, ...)
{
    va_list args;
    va_start(args, str);
    if (!str)
        return (0);
    int count = parse_string(str, args);
    va_end(args);
    return count;
}

#include <stdio.h>

int 	main (void)
{
	my_printf("Here is a string: \n");
	my_printf("Hello, %s! %d %x\n", "world", 42, 42);
	my_printf("2025 in hexadecimal is: %x\n", 2025);
    my_printf(NULL);
    my_printf(", %s", "");
	my_printf("\n");

	printf("Here is a string: \n");
	printf("Hello, %s! %d %x\n", "world", 42, 42);
	printf("2025 in hexadecimal is: %x\n", 2025);
    printf(NULL);
    printf(", %s", "");
	printf("\n");

	return 0;
}

/*result should be : 


Here is a string: 
Hello, world! 42 2a
2025 in hexadecimal is: 7e9
,
Here is a string: 
Hello, world! 42 2a
2025 in hexadecimal is: 7e9
,

*/