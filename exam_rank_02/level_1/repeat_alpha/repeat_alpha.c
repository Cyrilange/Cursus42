#include <unistd.h>

void repeat_alpha(char *str)
{
    int i = 0;
    int c;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            c = str[i] - 'a' + 1;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            c = str[i] - 'A' + 1;
        }
        else 
        {
            c = 1;
        }
        while (c--)
        {
            write(1, &str[i], 1);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        repeat_alpha(argv[1]);
    }
    write(1, "\n", 1);
    return (0);
}