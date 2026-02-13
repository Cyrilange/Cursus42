/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-09 12:04:53 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-09 12:04:53 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	builtin_exit(char **command)
{
	int	i;

	ft_putendl_fd("exit!!!!", 2);
	if (matrix_len(command) > 2)
		return (ft_putendl_fd("exit: too many arguments", 2), 1);
	if (command[1] == NULL)
		exit(0);
	i = 0;
	while (command[1][i] != '\0')
	{
		if (!ft_isdigit(command[1][i]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(command[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(2);
		}
		i++;
	}
	exit(ft_atoi(command[1]));
}
