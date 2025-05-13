#include "../includes/minishell.h"
#include <unistd.h>

int main(void)
{
    while (1)
    {
        char *input = get_input();

        command(input);

        free(input);
    }
    return 0;
}
