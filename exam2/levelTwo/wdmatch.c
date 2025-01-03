/*
Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "forty two" "qfqfsoudf arzgrsayns tsryegftdgs sjytwdekuooixq " | cat -e
forty two$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
*/
#include <unistd.h>

int duplicate(char *str, char c, int pos)
{
    int i = 0;
    while (i < pos)
    {
        if (str[i] == c)
            return 1;
            i++;
    }
    return 0;
}

void    wdmatch(char *s1, char *s2)
{
    int i = 0;
    int j;
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
                if (!duplicate(s2, s2[j], j))
                    write(1, &s1[i], 1);
            j++;
        }
        i++;
    }
}

#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 3)
        wdmatch(argv[1], argv[2]);
    write(1, "\n", 1);
    return 0;

}