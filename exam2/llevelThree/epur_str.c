/*Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>*/

#include <unistd.h>

void    epur_str(char *str)
{
    int i = 0;
    int word = 1;
    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    while (str[i])
    {
        
        if (!word && (str[i] != ' ' && str[i] != '\t'))
            write(1, " ", 1);
       
        while (str[i] && str[i] != ' ' && str[i] != '\t')
        {
            write(1, &str[i], 1);
            i++;
        }
        while (str[i] ==  ' ' || str[i] == '\t')
            i++;
        word = 0;
    }
    
}

int main(int argc, char **argv)
{
    if (argc == 2)
        epur_str(argv[1]);
    write(1, "\n", 1);
    return 0;
}