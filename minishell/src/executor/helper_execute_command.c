/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_execute_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-09 11:10:45 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-09 11:10:45 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_status;

bool	it_is_path(const char *cmd)
{
	if (!cmd)
		return (false);
	if (strchr(cmd, '/'))
		return (true);
	return (false);
}

int	helper_exec_xmd_path(char **resolved_path, char *save_cmd_name,
		bool should_free)
{
	g_status = 127;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(save_cmd_name, 2);
	ft_putstr_fd(": command not found\n", 2);
	if (should_free && *resolved_path)
		free(*resolved_path);
	return (1);
}

int	helper_handle_builtin(char **command, char ***envp)
{
	if (!command || !command[0])
		return (1);
	if (is_builtin(command[0]) == true)
	{
		g_status = execute_builtin(command, envp);
		return (0);
	}
	return (-1);
}

char	*helper_resolve_path(char *cmd, char **envp, bool *should_free)
{
	char	*resolved_path;

	resolved_path = NULL;
	if (!it_is_path(cmd))
	{
		get_cmd_path(envp, &resolved_path, cmd);
		*should_free = true;
	}
	else
	{
		resolved_path = cmd;
		*should_free = false;
	}
	return (resolved_path);
}

int	helper_exec_process(char *resolved_path, char **command, char **envp,
		bool should_free)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(resolved_path, command, envp);
		ft_putstr_fd("execve", 2);
		if (should_free)
			free(resolved_path);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &g_status, 0);
		g_status = g_status / 256;
	}
	else
	{
		if (should_free)
			free(resolved_path);
		return (1);
	}
	if (should_free)
		free(resolved_path);
	return (0);
}
