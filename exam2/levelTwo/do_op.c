/*Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %
The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.
You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

******************************
*                            *
* We can use printf and atoi *
*                            *
******************************

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$*/
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int i = 0;
    int num1;
    int num2;
    if (argc == 4)
    {
        num1 = atoi(argv[1]);
        num2 = atoi(argv[3]);
        if (argv[2][0] == '+')
            printf("%d", num1 + num2);
        else if (argv[2][0] == '-')
            printf("%d", num1 - num2);
        else if (argv[2][0] == '*')
            printf("%d", num1 * num2);
        else if (argv[2][0] == '/')
            printf("%d", num1 / num2);
        else if (argv[2][0] == '%')
            printf("%d", num1 % num2);
          
    
    }
    printf("\n"   );
    return 0;
}