#include "../includes/minishell.h"

int ft_echo(char **args)
{
    int newline = 1;
    int i = 1;

    if (args[1] && strcmp(args[1], "-n") == 0)
    {
        newline = 0;
        i++;
    }
    while (args[i])
    {
        printf("%s", args[i]);
        if (args[i + 1])
            printf(" ");
        i++;
    }

    if (newline)
        printf("\n");
    return 0;
}