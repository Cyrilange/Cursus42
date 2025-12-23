/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:34:08 by mariogo2          #+#    #+#             */
/*   Updated: 2025/08/08 22:30:57 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_token(t_token *token, char **args, int *arg_i, char **envp)
{
	if (token->quote_type != SINGLE_QUOTE)
		args[(*arg_i)++] = expand_variables(token->value, token->quote_type,
				envp);
	else
		args[(*arg_i)++] = ft_strdup(token->value);
}

static void	child_process(t_cmd_node *cmd, int pipe_fd[2], int in_fd,
		char ***envp)
{
	if (cmd->next)
		dup2(pipe_fd[1], STDOUT_FILENO);
	if (in_fd != 0)
		dup2(in_fd, STDIN_FILENO);
	if (cmd->cmd->infile)
		redirect_infile(cmd->cmd->infile);
	if (cmd->cmd->outfile)
		redirect_outfile(cmd->cmd->outfile, cmd->cmd->append);
	close(pipe_fd[0]);
	execute_command(cmd->cmd->args, envp);
	exit(1);
}

void	execute_pipeline(t_cmd_node *cmds, char ***envp)
{
	int		pipe_fd[2];
	int		in_fd;
	pid_t	pid;

	in_fd = 0;
	while (cmds)
	{
		if (cmds->next && pipe(pipe_fd) < 0)
			return (perror("pipe"));
		pid = fork();
		if (pid == 0)
		{
			child_process(cmds, pipe_fd, in_fd, envp);
		}
		close(pipe_fd[1]);
		if (in_fd != 0)
			close(in_fd);
		in_fd = pipe_fd[0];
		cmds = cmds->next;
	}
	while (wait(NULL) > 0)
		;
}
