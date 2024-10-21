#include <unistd.h>

void    first_word(char *str)
{
    int i = 0;
    while (str[i] == '\t' || str[i] == ' ')
        i++;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        if (str[i] == '\t' || str[i] == ' ')
            break;
        i++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        first_word(argv[1]);
        return (1);
    }
    write(1, "\n", 1);
    return (0);
}