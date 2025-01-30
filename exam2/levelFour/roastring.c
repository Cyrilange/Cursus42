#include <unistd.h>

void    rostring(char *str)
{
    int i = 0;
    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    int start = i;
    while (str[i] && str[i] != ' ' && str[i] != '\t')
        i++;
    int end = i;
    int flag = 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (flag && (str[i] != ' ' && str[i] != '\t'))
        {
            write(1, " ", 1);
        }

        while (str[i] && str[i] != ' ' && str[i] != '\t')
        {
            write(1, &str[i], 1);
            i++;
        }
        flag = 1;
    }
    if (start < end)
    {
        if (str[i] && str[i] != ' ' && str[i] != '\t')
        {
            write(1, " ", 1);
        }
        while (start < end)
        {
            write(1, &str[start], 1);
            start++;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rostring(argv[1]);
    write(1, "\n", 1);
    return 0;
}

