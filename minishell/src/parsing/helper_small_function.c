/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_small_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:34:02 by mariogo2          #+#    #+#             */
/*   Updated: 2025/08/08 22:30:58 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_var_char(char c)
{
	return (ft_isalnum(c) || c == '_');
}

int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

int	is_special(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '&' || c == ';' || c == '('
		|| c == ')');
}

t_quotes	get_quote_type(char c)
{
	if (c == '\'')
		return (SINGLE_QUOTE);
	if (c == '"')
		return (DOUBLE_QUOTE);
	return (NO_QUOTE);
}

t_token	*create_token(char *value, t_quotes quote_type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = value;
	token->quote_type = quote_type;
	return (token);
}
