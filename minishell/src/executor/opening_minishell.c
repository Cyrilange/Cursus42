/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opening_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-09 11:25:31 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-09 11:25:31 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

static void	handle_cmd_node(t_cmd_node *node, char ***envp)
{
	pid_t	pid;

	if (node->cmd->invalid_syntax)
		return ;
	if (node->cmd->heredoc || node->cmd->infile || node->cmd->outfile)
	{
		pid = fork();
		if (pid == 0)
		{
			if (node->cmd->heredoc)
				handle_heredoc_if_needed(node->cmd);
			if (node->cmd->infile)
				redirect_infile(node->cmd->infile);
			if (node->cmd->outfile)
				redirect_outfile(node->cmd->outfile, node->cmd->append);
			execute_command(node->cmd->args, envp);
			exit(1);
		}
		else
			waitpid(pid, &g_status, 0);
	}
	else
		execute_command(node->cmd->args, envp);
}

static void	execute_cmds(t_cmd_node *cmds, char ***envp)
{
	t_cmd_node	*tmp;

	tmp = cmds;
	while (tmp)
	{
		handle_cmd_node(tmp, envp);
		tmp = tmp->next;
	}
}

static void	free_tokens(t_token **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]->value);
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static void	execute_parsed_cmds(t_cmd_node *cmds, char ***envp)
{
	if (cmds && cmds->next)
		execute_pipeline(cmds, envp);
	else
		execute_cmds(cmds, envp);
}

void	command(char *input, char ***envp)
{
	t_token		**tokens;
	t_cmd_node	*cmds;
	t_pipe_ctx	*ctx;

	ctx = malloc(sizeof(t_pipe_ctx));
	if (!input || !*input)
		return ;
	tokens = tokenize_input(input);
	if (!tokens)
		return ;
	cmds = parse_pipeline_tokens(tokens, *envp, ctx);
	expand_tildes_in_tokens(tokens, *envp);
	execute_parsed_cmds(cmds, envp);
	update_pwd(envp);
	free_cmd_list(cmds);
	free_tokens(tokens);
	free(ctx);
}
