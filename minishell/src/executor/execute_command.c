/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-09 11:06:05 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-09 11:06:05 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_status;

int	execute_command(char **command, char ***envp)
{
	char	*save_cmd_name;
	char	*resolved_path;
	bool	should_free;
	int		builtin_result;

	should_free = false;
	builtin_result = helper_handle_builtin(command, envp);
	if (builtin_result != -1)
		return (builtin_result);
	save_cmd_name = command[0];
	resolved_path = helper_resolve_path(command[0], *envp, &should_free);
	if (!resolved_path || access(resolved_path, X_OK) == -1)
	{
		helper_exec_xmd_path(&resolved_path, save_cmd_name, should_free);
		return (1);
	}
	return (helper_exec_process(resolved_path, command, *envp, should_free));
}
