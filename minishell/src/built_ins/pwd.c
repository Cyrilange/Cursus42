/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-09 12:05:05 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-09 12:05:05 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	replace_env_var(char ***envp, char *varname, char *value)
{
	int		var_position;
	char	*tmp;
	char	**tmp_envp;

	var_position = is_in_envp(varname, *envp);
	tmp = ft_strjoin(varname, value);
	if (var_position == -1)
		*envp = matrix_str_add(*envp, tmp);
	else
	{
		tmp_envp = matrix_str_dup(*envp, var_position, tmp);
		matrix_free(envp);
		*envp = tmp_envp;
	}
	free(tmp);
	return ;
}

void	update_pwd(char ***envp)
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		replace_env_var(envp, "PWD=", cwd);
}

int	builtin_pwd(void)
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)))
	{
		printf("%s\n", cwd);
		return (0);
	}
	return (1);
}
