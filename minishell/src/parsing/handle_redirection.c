/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:33:41 by mariogo2          #+#    #+#             */
/*   Updated: 2025/08/08 22:30:56 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

static void	handle_output_redirection(t_token **tokens, int *i, t_cmd *cmd)
{
	(*i)++;
	if (!tokens[*i])
	{
		write(2, "syntax error near unexpected token `newline'\n", 45);
		cmd->invalid_syntax = 1;
		g_status = 258;
		return ;
	}
	if (cmd->outfile)
		free(cmd->outfile);
	cmd->outfile = ft_strdup(tokens[*i]->value);
	(*i)++;
}

static void	handle_append_redirection(t_token **tokens, int *i, t_cmd *cmd)
{
	(*i)++;
	if (!tokens[*i])
	{
		write(2, "syntax error near unexpected token `newline'\n", 45);
		cmd->invalid_syntax = 1;
		g_status = 258;
		return ;
	}
	if (cmd->outfile)
		free(cmd->outfile);
	cmd->outfile = ft_strdup(tokens[*i]->value);
	cmd->append = 1;
	(*i)++;
}

static void	handle_input_redirection(t_token **tokens, int *i, t_cmd *cmd)
{
	(*i)++;
	if (!tokens[*i])
	{
		write(2, "syntax error near unexpected token `newline'\n", 45);
		cmd->invalid_syntax = 1;
		g_status = 258;
		return ;
	}
	if (cmd->infile)
		free(cmd->infile);
	cmd->infile = ft_strdup(tokens[*i]->value);
	(*i)++;
}

static void	handle_heredoc_redirection(t_token **tokens, int *i, t_cmd *cmd)
{
	(*i)++;
	if (!tokens[*i])
	{
		write(2, "syntax error near unexpected token `newline'\n", 45);
		cmd->invalid_syntax = 1;
		g_status = 258;
		return ;
	}
	if (cmd->heredoc_delimiter)
		free(cmd->heredoc_delimiter);
	cmd->heredoc_delimiter = ft_strdup(tokens[*i]->value);
	cmd->heredoc = 1;
	(*i)++;
}

void	handle_redirection(t_token **tokens, int *i, t_cmd *cmd)
{
	if (!ft_strcmp(tokens[*i]->value, ">"))
		handle_output_redirection(tokens, i, cmd);
	else if (!ft_strcmp(tokens[*i]->value, ">>"))
		handle_append_redirection(tokens, i, cmd);
	else if (!ft_strcmp(tokens[*i]->value, "<"))
		handle_input_redirection(tokens, i, cmd);
	else if (!ft_strcmp(tokens[*i]->value, "<<"))
		handle_heredoc_redirection(tokens, i, cmd);
}
