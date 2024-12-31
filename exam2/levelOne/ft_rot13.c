/*Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.
'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.
The output will be followed by a newline.
If the number of arguments is not 1, the program displays a newline.
Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>*/

#include <unistd.h>

void    rot_13(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = (str[i] - 'a' + 13) % 26 + 'a';
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = (str[i] - 'A' + 13) % 26 + 'A';
        else
            str[i] = str[i];
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rot_13(argv[1]);
    write(1, "\n", 1);
    return 0;
}