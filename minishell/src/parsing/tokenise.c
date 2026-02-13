/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:48:15 by mariogo2          #+#    #+#             */
/*   Updated: 2025/08/08 22:30:59 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	parse_quoted_value(t_prompt *data, char *result, int *pos)
{
	char	quote;

	quote = data->input[data->i++];
	while (data->input[data->i] && data->input[data->i] != quote)
		result[(*pos)++] = data->input[data->i++];
	if (data->input[data->i] == quote)
		data->i++;
}

static void	parse_unquoted_value(t_prompt *data, char *result, int *pos)
{
	while (data->input[data->i] && !isspace((unsigned char)data->input[data->i])
		&& !is_special(data->input[data->i]))
	{
		result[(*pos)++] = data->input[data->i++];
	}
}

static t_token	*parse_assignment(t_prompt *data)
{
	char	*result;
	int		pos;
	char	*final_result;

	pos = 0;
	result = malloc(1000);
	while (data->input[data->i] && data->input[data->i] != '=')
		result[pos++] = data->input[data->i++];
	if (data->input[data->i] == '=')
	{
		result[pos++] = data->input[data->i++];
		if (data->input[data->i] == '"' || data->input[data->i] == '\'')
			parse_quoted_value(data, result, &pos);
		else if (data->input[data->i] == '$')
			result[pos++] = data->input[data->i++];
		else
			parse_unquoted_value(data, result, &pos);
	}
	result[pos] = '\0';
	final_result = ft_strdup(result);
	free(result);
	return (create_token(final_result, NO_QUOTE));
}

static t_token	*extract_token(t_prompt *data)
{
	char	c;

	c = data->input[data->i];
	if (is_assignment_start(data))
		return (parse_assignment(data));
	if (c == '>' || c == '<')
		return (parse_redirection(data));
	if (c == '|')
	{
		data->i++;
		return (create_token(ft_strdup("|"), NO_QUOTE));
	}
	if (c == '\'' || c == '"')
		return (parse_quote(data));
	return (parse_word(data));
}

t_token	**tokenize_input(char *input)
{
	t_prompt	data;
	t_token		**tokens;
	int			i;

	data.input = input;
	data.i = 0;
	tokens = malloc(sizeof(t_token *) * MAX_ARGS);
	if (!tokens)
		return (NULL);
	i = 0;
	while (input[data.i])
	{
		while (ft_isspace(input[data.i]))
			data.i++;
		if (!input[data.i])
			break ;
		tokens[i++] = extract_token(&data);
	}
	tokens[i] = NULL;
	return (tokens);
}
