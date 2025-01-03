/*Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"*/
#include <unistd.h>

void	print_bits(unsigned char octet)
{
    int bit = 7; // 7 because it is 8 bits from 0 to 7;
    while (bit >= 0)
    {
        if ((octet >> bit) & 1)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        bit--;
    }
}

#include <stdio.h>

int main(void)
{
    print_bits(0);
    printf("\n");
    print_bits(1);
    printf("\n");
    print_bits(2);
    printf("\n");
    print_bits(3);
    printf("\n");
    print_bits(4);
    printf("\n");
    print_bits(5);
    printf("\n");
    print_bits(6);
    printf("\n");
    print_bits(7);
    printf("\n");
    print_bits(8);
    printf("\n");
    print_bits(9);
    printf("\n");
    print_bits(10);
    printf("\n");
    print_bits(11);
    printf("\n");
    print_bits(100);
    printf("\n");
    return 0;
}