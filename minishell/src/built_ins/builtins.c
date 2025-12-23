/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-09 12:04:33 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-09 12:04:33 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	is_builtin(char *command)
{
	if (command == NULL)
		return (false);
	else if (ft_strcmp(command, "cd") == 0)
		return (true);
	else if (ft_strcmp(command, "echo") == 0)
		return (true);
	else if (ft_strcmp(command, "env") == 0)
		return (true);
	else if (ft_strcmp(command, "exit") == 0)
		return (true);
	else if (ft_strcmp(command, "export") == 0)
		return (true);
	else if (ft_strcmp(command, "pwd") == 0)
		return (true);
	else if (ft_strcmp(command, "unset") == 0)
		return (true);
	return (false);
}

int	execute_builtin(char **args, char ***envp)
{
	int	retvalue;

	if (ft_strcmp(args[0], "cd") == 0)
	{
		retvalue = builtin_cd(args[1], envp);
		update_pwd(envp);
		return (retvalue);
	}
	else if (ft_strcmp(args[0], "echo") == 0)
		return (builtin_echo(args));
	else if (ft_strcmp(args[0], "pwd") == 0)
		return (builtin_pwd());
	else if (ft_strcmp(args[0], "exit") == 0)
		return (builtin_exit(args));
	else if (ft_strcmp(args[0], "export") == 0)
		return (builtin_export(args, envp));
	else if (ft_strcmp(args[0], "unset") == 0)
		return (builtin_unset(args, envp, 0, NULL));
	else if (ft_strcmp(args[0], "env") == 0)
		return (builtin_env(*envp));
	return (0);
}
