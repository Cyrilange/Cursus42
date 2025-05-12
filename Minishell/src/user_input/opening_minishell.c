//#include "../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <string.h>

int	is_builtin(const char *cmd)
{
	if (!cmd)
		return (0);
	return (
		strcmp(cmd, "cd") == 0 ||
		strcmp(cmd, "echo") == 0 ||
		strcmp(cmd, "exit") == 0 ||
		strcmp(cmd, "pwd") == 0 ||
		strcmp(cmd, "export") == 0 ||
		strcmp(cmd, "unset") == 0 ||
		strcmp(cmd, "env") == 0
	);
}

void command(char *input)
{
	if (!input || !*input) 
		return;

	char **args = malloc(sizeof(char *) * 2);
	if (!args)
		return;
	args[0] = strtok(input, " \t\n");
	args[1] = NULL;

	if (!args[0])
	{
		free(args);
		return;
	}

	if (is_builtin(args[0]))
	{
		printf("Builtin command: %s\n", args[0]);
	}
	else
	{
		printf("minishell: %s: command not found\n", args[0]);
	}

	free(args);
}


char *get_input(void)
{
    char *input;

    input = readline("minishell> ");//opening minishell
    if (!input)
    {
        printf("exit\n");
        exit(0);
    }

    if (input && *input)
        add_history(input);

    return input;
}

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
