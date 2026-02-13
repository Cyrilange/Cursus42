/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-09 12:04:39 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-09 12:04:39 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	change_pwd(char ***envp)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (1);
	free(cwd);
	cwd = get_env_var_value("PWD", *envp);
	update_pwd(envp);
	free(cwd);
	return (0);
}

static int	cd_home(char ***envp)
{
	char	*home;
	char	*pwd;

	home = get_env_var_value("HOME", *envp);
	pwd = get_env_var_value("PWD", *envp);
	if (pwd)
		replace_env_var(envp, "OLDPWD=", pwd);
	if (!home)
	{
		write(2, "minishell: cd: HOME not set\n", 29);
		return (1);
	}
	if (chdir(home) == 0)
	{
		replace_env_var(envp, "PWD=", home);
		free(home);
		free(pwd);
		return (0);
	}
	free(home);
	free(pwd);
	return (1);
}

static int	cd_error(char *path)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int	builtin_cd(char *path, char ***envp)
{
	char	*pwd;

	if (!path || *path == '\0')
		return (cd_home(envp));
	if (chdir(path) != 0)
		return (cd_error(path));
	pwd = get_env_var_value("PWD", *envp);
	if (pwd)
		replace_env_var(envp, "OLDPWD=", pwd);
	return (free(pwd), change_pwd(envp));
}
