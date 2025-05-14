#ifndef MINISHELL_H
#define MINISHELL_H


#define MAX_ARGS 1024


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include "./libft.h"

typedef struct s_data
{
	char	*input;
	char	**args;
	int		i;
}	t_data;


int	is_builtin(const char *cmd);
void command(char *input);
char *get_input();



int ft_cd(char *path);


void update_pwd(void);
int ft_pwd(void);


int ft_echo(char **args);

#endif