/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_tokenise.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-09 10:11:36 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-09 10:11:36 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*parse_redirection(t_prompt *data)
{
	int	start;

	start = data->i;
	if (data->input[data->i + 1] && data->input[data->i] == data->input[data->i
			+ 1])
		data->i += 2;
	else
		data->i++;
	return (create_token(ft_strndup(&data->input[start], data->i - start),
			NO_QUOTE));
}

t_token	*parse_quote(t_prompt *data)
{
	int			start;
	int			len;
	t_quotes	quote;

	quote = get_quote_type(data->input[data->i]);
	data->i++;
	start = data->i;
	while (data->input[data->i])
	{
		if (get_quote_type(data->input[data->i]) == quote)
			break ;
		data->i++;
	}
	len = data->i - start;
	if (data->input[data->i])
		data->i++;
	return (create_token(ft_strndup(&data->input[start], len), quote));
}

t_token	*parse_word(t_prompt *data)
{
	int	start;
	int	len;

	start = data->i;
	len = 0;
	while (data->input[data->i] && !isspace((unsigned char)data->input[data->i])
		&& !is_quote(data->input[data->i]) && !is_special(data->input[data->i]))
	{
		data->i++;
		len++;
	}
	return (create_token(ft_strndup(&data->input[start], len), NO_QUOTE));
}

int	is_assignment_start(t_prompt *data)
{
	int	temp_i;

	temp_i = data->i;
	if (!isalpha(data->input[temp_i]) && data->input[temp_i] != '_')
		return (0);
	while (data->input[temp_i] && (isalnum(data->input[temp_i])
			|| data->input[temp_i] == '_'))
		temp_i++;
	return (data->input[temp_i] == '=');
}
