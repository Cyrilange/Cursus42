/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_while_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:33:28 by mariogo2          #+#    #+#             */
/*   Updated: 2025/08/08 22:31:00 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	handle_pipe(t_pipe_ctx *ctx)
{
	add_cmd_node(&ctx->pctx);
	init_parse(&ctx->pctx);
}

static int	is_pipe_token(t_token *token)
{
	return (!ft_strcmp(token->value, "|") && token->quote_type == NO_QUOTE);
}

static int	is_redirect_token(t_token *token)
{
	return (!ft_strcmp(token->value, ">") || !ft_strcmp(token->value, ">>")
		|| !ft_strcmp(token->value, "<") || !ft_strcmp(token->value, "<<"));
}

void	condition_while_pipe(t_pipe_ctx *ctx)
{
	t_token	*token;

	token = ctx->tokens[ctx->i];
	if (!ft_strcmp(token->value, "<<"))
	{
		ctx->pctx.cmd->heredoc = 1;
		ctx->i++;
		if (ctx->tokens[ctx->i])
			ctx->pctx.cmd->heredoc_delimiter
				= ft_strdup(ctx->tokens[ctx->i++]->value);
	}
	else if (is_pipe_token(token))
	{
		handle_pipe(ctx);
		ctx->i++;
	}
	else if (is_redirect_token(token))
		handle_redirection(ctx->tokens, &ctx->i, ctx->pctx.cmd);
	else
	{
		handle_token(token, ctx->pctx.args, &ctx->pctx.arg_i, ctx->envp);
		ctx->i++;
	}
}
