/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:33:34 by mariogo2          #+#    #+#             */
/*   Updated: 2025/08/08 22:30:55 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*handle_heredoc(char *delimiter)
{
	char	*line;
	int		fd;

	fd = open("/tmp/.heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd < 0)
		return (NULL);
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(line, delimiter))
			break ;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	free(line);
	close(fd);
	return (ft_strdup("/tmp/.heredoc_tmp"));
}

static void	setup_input_redirection(t_cmd *cmd)
{
	char	*heredoc_file;

	if (cmd->heredoc)
	{
		heredoc_file = handle_heredoc(cmd->heredoc_delimiter);
		if (!heredoc_file)
			exit(1);
		redirect_infile(heredoc_file);
		free(heredoc_file);
	}
	else if (cmd->infile)
		redirect_infile(cmd->infile);
}

static void	setup_output_redirection(t_cmd *cmd)
{
	int	flags;
	int	fd;

	if (!cmd->outfile)
		return ;
	flags = O_CREAT | O_WRONLY;
	if (cmd->append)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	fd = open(cmd->outfile, flags, 0644);
	if (fd < 0)
	{
		write(STDERR_FILENO, "open outfile", 13);
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	handle_heredoc_if_needed(t_cmd *cmd)
{
	setup_input_redirection(cmd);
	setup_output_redirection(cmd);
}
