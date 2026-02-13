/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-09 11:24:06 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-09 11:24:06 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

char	*get_here_str(char *delim)
{
	char	*prompt;
	char	*doc;

	while (ft_strcmp(delim, prompt) != 0)
	{
		doc = ft_strjoin(doc, prompt);
		prompt = readline("> ");
		doc = ft_strjoin("\n", doc);
	}
	return (doc);
}
