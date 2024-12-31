/*Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.
'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...
Case remains unchanged.
If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>*/

#include <unistd.h>

void    repeat_alpha(char *str)
{
    int i = 0;
    int count;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            count = str[i] - 'a' + 1;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            count = str[i] - 'A' + 1;
        else
            count = 1;
        while (count--)
        {
            write(1, &str[i], 1);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        repeat_alpha(argv[1]);
    write(1, "\n", 1);
    return 0;
}