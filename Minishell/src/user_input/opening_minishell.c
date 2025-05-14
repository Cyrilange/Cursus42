#include "../includes/minishell.h"
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
int	execute_builtin(char **args)
{
	if (strcmp(args[0], "cd") == 0)
		return ft_cd(args[1]);
	else if (strcmp(args[0], "echo") == 0)
        return ft_echo(args);
	else if (strcmp(args[0], "pwd") == 0)
        return ft_pwd();
	return 0;
}


void command(char *input)
{
	if (!input || !*input) 
		return;
	char *token = strtok(input, " \t\n"); //need praseing
	if (!token)
		return;
	char *word = strtok(input, " \t\n"); //need parsing
	int i = 0;
	char **args = malloc(sizeof(char *) * (MAX_ARGS + 1));
	while (word && i < MAX_ARGS)
	{
		args[i] = word;
		i++;
		word = strtok(word + ft_strlen(args[i - 1]), " \t\n"); //need parsing
	}
	args[i] = NULL;
	i = 0;
	/*while (args[i])
	{
		printf("%s\n", args[i]);
		i++;
	}*/
	if (is_builtin(args[0]))
	{
		execute_builtin(args);
	}
	else
	{
		write(2, "minishell: ", 11);
		write(2, args[0], ft_strlen(args[0]));
		write(2, ": command not found\n", 21);
	}

	free(args);
}
//acascws

char	*get_input()
{
	t_data input;
    char *cwd = getenv("PWD");

    if (cwd)
    {
        printf("\033[0;32mminishell> \033[0;34m%s\033[0m $ ", cwd);
    }
    else
    {
        printf("\033[0;32mminishell> \033[0m$ ");
    }

    input.input = readline(NULL);

	//printf("%s\n", input.input);

    if (!input.input)
    {
        printf("exit\n");
        exit(0);
    }

    if (input.input && *(input.input))
        add_history(input.input);

    return input.input;
}
