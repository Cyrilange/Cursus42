/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-09 11:31:53 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-09 11:31:53 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_path_variable(char **envp)
{
	int		i;
	char	*variable;

	i = 0;
	while (envp[i] != NULL)
	{
		variable = ft_substr(envp[i], 0, 5);
		if (ft_strncmp("PATH=", variable, 5) == 0)
			return (free(variable), &envp[i][5]);
		free(variable);
		i++;
	}
	return (NULL);
}

char	*ret_path_if_exists(char **list_of_paths, char *program_name)
{
	int		i;
	char	*program_path;
	char	*temp;

	i = 0;
	while (list_of_paths[i] != NULL)
	{
		temp = ft_strjoin(list_of_paths[i], "/");
		program_path = ft_strjoin(temp, program_name);
		free(temp);
		if (!access(program_path, X_OK))
			return (program_path);
		free(program_path);
		i++;
	}
	return (NULL);
}

int	get_cmd_path(char **envp, char **binpath, char *cmd)
{
	char	**list_of_paths;
	char	*single_line_path;

	single_line_path = get_path_variable(envp);
	if (single_line_path == NULL)
		return (127);
	list_of_paths = ft_split(single_line_path, ':');
	if (list_of_paths == NULL)
		return (127);
	*binpath = ret_path_if_exists(list_of_paths, cmd);
	free_double_ptr((void **)list_of_paths);
	if (*binpath == NULL)
		return (127);
	return (0);
}
