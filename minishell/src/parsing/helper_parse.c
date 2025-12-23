/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:33:50 by mariogo2          #+#    #+#             */
/*   Updated: 2025/08/08 22:30:56 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	quotes_are_closed(const char *str)
{
	int	single;
	int	dbl;
	int	i;

	single = 0;
	dbl = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' && dbl % 2 == 0)
			single++;
		else if (str[i] == '"' && single % 2 == 0)
			dbl++;
		i++;
	}
	return (single % 2 == 0 && dbl % 2 == 0);
}

char	*read_multiline_command(t_prompt *prompt)
{
	char	*line;
	char	*full_line;
	char	*tmp;

	line = readline(PROMPT);
	if (line == NULL)
		cleanup(prompt);
	set_signals_noninteractive();
	if (!line)
		return (NULL);
	full_line = ft_strdup(line);
	free(line);
	while (!quotes_are_closed(full_line))
	{
		line = readline(">");
		if (!line)
			return (free(full_line), NULL);
		tmp = ft_strjoin(full_line, "\n");
		free(full_line);
		full_line = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	return (full_line);
}

void	free_double_ptr(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
