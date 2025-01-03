/*Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100*/
#include <unistd.h>


unsigned char	swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}

#include <stdio.h>

int main(void)
{
    unsigned char octet = 2;                   // Valeur binaire : 00000010
    unsigned char swapped = swap_bits(octet);  // Échange des bits
    printf("Original: %u\n", octet);           // Affiche : 2
    printf("Swapped: %u\n", swapped);          // Affiche : 32 (binaire : 00100000)
    return 0;
}