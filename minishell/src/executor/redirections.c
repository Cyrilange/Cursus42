/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-09 11:29:36 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-09 11:29:36 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

void	redirect_outfile(char *fil, bool append)
{
	int	outfile_fd;

	if (append == true)
		outfile_fd = open(fil, O_WRONLY | O_APPEND | O_CREAT,
				S_IRUSR | S_IWUSR);
	else
		outfile_fd = open(fil, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
}

void	redirect_infile(char *fil)
{
	int	infile_fd;

	infile_fd = open(fil, O_RDONLY);
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
}

bool	is_path(char *command)
{
	int	i;

	i = 0;
	if (command == NULL)
		return (false);
	while (command[i] != '\0')
	{
		if (command[i] == '/')
			return (true);
		i++;
	}
	return (false);
}
