/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:34:14 by mariogo2          #+#    #+#             */
/*   Updated: 2025/08/08 22:30:57 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_parse(t_parse_ctx *pctx)
{
	int	i;

	i = 0;
	pctx->cmd = calloc(1, sizeof(t_cmd));
	if (!pctx->cmd)
		return ;
	free(pctx->cmd->args);
	pctx->cmd->args = NULL;
	pctx->cmd->infile = NULL;
	pctx->cmd->outfile = NULL;
	pctx->cmd->append = 0;
	pctx->cmd->heredoc = 0;
	pctx->cmd->heredoc_delimiter = NULL;
	pctx->cmd->invalid_syntax = 0;
	pctx->args = malloc(sizeof(char *) * (MAX_ARGS + 1));
	if (!pctx->args)
		return ;
	while (i <= MAX_ARGS)
	{
		pctx->args[i] = NULL;
		i++;
	}
	pctx->arg_i = 0;
}

void	add_cmd_node(t_parse_ctx *pctx)
{
	t_cmd_node	*node;

	pctx->args[pctx->arg_i] = NULL;
	pctx->cmd->args = pctx->args;
	node = malloc(sizeof(t_cmd_node));
	if (!node)
	{
		free(pctx->cmd->args);
		free(pctx->cmd);
		return ;
	}
	node->cmd = pctx->cmd;
	node->next = NULL;
	if (!*pctx->cmds)
		*pctx->cmds = node;
	else
		(*pctx->last)->next = node;
	*pctx->last = node;
}

void	process_token(t_token *token, char **args, int *arg_i, char **envp)
{
	if (token->quote_type != SINGLE_QUOTE)
		args[(*arg_i)++] = expand_variables(token->value, token->quote_type,
				envp);
	else
		args[(*arg_i)++] = ft_strdup(token->value);
}

t_cmd_node	*parse_pipeline_tokens(t_token **tokens, char **envp,
		t_pipe_ctx *ctx)
{
	t_cmd_node	*cmds;
	t_cmd_node	*last;

	cmds = NULL;
	last = NULL;
	ctx->tokens = tokens;
	ctx->i = 0;
	ctx->pctx.cmds = &cmds;
	ctx->pctx.last = &last;
	init_parse(&ctx->pctx);
	ctx->envp = envp;
	while (ctx->tokens[ctx->i])
		condition_while_pipe(ctx);
	add_cmd_node(&ctx->pctx);
	return (cmds);
}
